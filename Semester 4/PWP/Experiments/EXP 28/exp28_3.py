import tkinter as tk

window = tk.Tk()
window.title("EXP 28.3")
var = tk.IntVar(value=2)

tk.Radiobutton(window, text="Option 1", variable=var, value=1).pack()
tk.Radiobutton(window, text="Option 2", variable=var, value=2).pack()

window.mainloop()
