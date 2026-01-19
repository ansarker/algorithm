import customtkinter as ctk
from tkinter import filedialog
import sorting
import visualize
import os

ctk.set_appearance_mode("Dark")
ctk.set_default_color_theme("blue")

class App(ctk.CTk):
    def __init__(self):
        super().__init__()
        self.title("PixelSort - Modern Algorithm Visualizer")
        self.geometry("500x600")

        self.label = ctk.CTkLabel(self, text="IMAGE SORTING ENGINE", font=("Roboto", 24, "bold"))
        self.label.pack(pady=20)

        self.file_btn = ctk.CTkButton(self, text="Select Image Source", command=self.select_file)
        self.file_btn.pack(pady=10)
        self.path_label = ctk.CTkLabel(self, text="No file selected", font=("Roboto", 10))
        self.path_label.pack()

        self.settings_frame = ctk.CTkFrame(self)
        self.settings_frame.pack(pady=20, padx=20, fill="x")

        self.width_input = ctk.CTkEntry(self.settings_frame, placeholder_text="Width (e.g. 60)")
        self.width_input.grid(row=0, column=0, padx=10, pady=10)
        
        self.height_input = ctk.CTkEntry(self.settings_frame, placeholder_text="Height (e.g. 60)")
        self.height_input.grid(row=0, column=1, padx=10, pady=10)

        self.algo_label = ctk.CTkLabel(self, text="Select Algorithms to Compare:")
        self.algo_label.pack()
        
        self.algos = ["quick", "merge", "heap", "bubble", "insertion", "selection", "shell", "cocktail_shaker"]
        self.check_vars = {}
        for algo in self.algos:
            var = ctk.BooleanVar()
            cb = ctk.CTkCheckBox(self, text=algo.capitalize(), variable=var)
            cb.pack(pady=2, padx=50, anchor="w")
            self.check_vars[algo] = var

        self.run_btn = ctk.CTkButton(self, text="GENERATE VISUALIZATION", 
                                     fg_color="#2ecc71", hover_color="#27ae60",
                                     command=self.start_engine)
        self.run_btn.pack(pady=30)

        self.selected_path = None

    def select_file(self):
        self.selected_path = filedialog.askopenfilename()
        self.path_label.configure(text=os.path.basename(self.selected_path))

    def start_engine(self):
        selected = {name: None for name, var in self.check_vars.items() if var.get()}
        w = int(self.width_input.get() or 60)
        h = int(self.height_input.get() or 60)
        
        ALGO_MAP = {
            "bubble": sorting.bubble_sort,
            "quick": lambda a: sorting.quick_sort(a, 0, len(a)-1),
            "merge": lambda a: sorting.merge_sort(a, 0, len(a)),
            "insertion": sorting.insertion_sort,
            "selection": sorting.selection_sort,
            "heap": sorting.heap_sort,
            "shell": sorting.shell_sort,
            "cocktail_shaker": sorting.cocktail_shaker_sort
        }
        
        final_algos = {n: ALGO_MAP[n] for n in selected if n in ALGO_MAP}
        
        cols = 2 if len(final_algos) <= 4 else 3
        rows = (len(final_algos) + cols - 1) // cols
        
        self.destroy()
        visualize.run_visualizer(self.selected_path, final_algos, (rows, cols), (w, h))

if __name__ == "__main__":
    app = App()
    app.mainloop()