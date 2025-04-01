import tkinter as tk

window = tk.Tk()
menu_bar = tk.Menu(window)

file_menu = tk.Menu(menu_bar)
file_menu.add_command(label="Exit", command=window.quit)
menu_bar.add_cascade(label="File", menu=file_menu)

window.config(menu=menu_bar)
window.mainloop()
