import cv2
import numpy as np
import time

def run_visualizer(image_path, selected_algos, grid_size, resize_dims):
    w_new, h_new = resize_dims
    img = cv2.imread(image_path)
    img = cv2.resize(img, (w_new, h_new))
    img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    
    h, w, c = img_rgb.shape
    flat_pixels = img_rgb.reshape(-1, c)
    n = len(flat_pixels)

    rows, cols = grid_size
    header_h = 70
    cell_w, cell_h = 300, 300
    
    fourcc = cv2.VideoWriter_fourcc(*'mp4v')
    out = cv2.VideoWriter("demo/output_render.mp4", fourcc, 30.0, (cols * cell_w, rows * (cell_h + header_h)))

    start_ts = time.time()
    active_sorts = []
    for name, algo_gen in selected_algos.items():
        state = np.random.permutation(n)
        active_sorts.append({
            "name": name.upper(),
            "gen": algo_gen(state.copy()),
            "state": state,
            "done": False,
            "time": "0.00s"
        })
    
    while any(not s["done"] for s in active_sorts):
        canvas = np.zeros((rows * (cell_h + header_h), cols * cell_w, 3), dtype=np.uint8)
        canvas[:] = (18, 18, 18) # Dark Background #121212

        for i, s in enumerate(active_sorts):
            r, c_idx = divmod(i, cols)
            x, y = c_idx * cell_w, r * (cell_h + header_h)

            if not s["done"]:
                try:
                    s["state"] = next(s["gen"])
                    s["time"] = f"{time.time() - start_ts:.2f}s"
                except StopIteration:
                    s["done"] = True

            frame = flat_pixels[s["state"]].reshape(h, w, 3)

            frame_bgr = cv2.cvtColor(frame, cv2.COLOR_RGB2BGR)
            frame_res = cv2.resize(frame_bgr, (cell_w - 20, cell_h - 20), interpolation=cv2.INTER_NEAREST)
            
            canvas[y + header_h : y + header_h + cell_h - 20, x + 10 : x + cell_w - 10] = frame_res

            cv2.rectangle(canvas, (x, y), (x + cell_w, y + header_h - 5), (30, 30, 30), -1)
            cv2.putText(canvas, s["name"], (x + 15, y + 30), 
                        cv2.FONT_HERSHEY_DUPLEX, 0.7, (255, 255, 255), 1)
            
            color = (0, 255, 100) if s["done"] else (100, 100, 100)
            cv2.putText(canvas, f"TIME: {s['time']}", (x + 15, y + 55), 
                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 1)

        out.write(canvas)
        cv2.imshow("PixelSort Engine - Rendering...", canvas)
        if cv2.waitKey(1) & 0xFF == ord('q'): break

    out.release()
    cv2.destroyAllWindows()
    print("Video Rendered Successfully.")