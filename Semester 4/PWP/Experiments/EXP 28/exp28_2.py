import tkinter as tk

window = tk.Tk()
window.title("EXP 28.2")

var = tk.BooleanVar()
tk.Checkbutton(window, text="Check me", variable=var).pack()

window.mainloop()
