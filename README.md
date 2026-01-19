### Installation

```bash
python -m venv .venv

source .venv/bin/activate

pip3 install -r requirements.txt
```

### How to run?

#### GUI
Just run the script: `python main.py` — This will pop up a window to pick your image and type your dimensions.

![User interface](doc/app_ui.png)

Rendering interface
![Rendering interface](doc/render.png)

#### CLI
Use CLI for automation: `python main.py --image my_pic.jpg --width 40 --height 40` — This bypasses the GUI.

**More in CLI:**

```bash
python main.py --image small.png --algos quick merge heap bubble insertion selection
```