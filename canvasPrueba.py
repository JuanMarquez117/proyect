import tkinter as tk
from tkinter import Canvas


ventana = tk.Tk()

canvas = Canvas(ventana, width= 740, height=580)
canvas.pack()

canvas.create_line(10,20,100,150, fill='#FF0000', width=3)

canvas.create_rectangle(150,120,250,180, outline='#00FF00', width=5)
canvas.create_rectangle(250,220,350,280, outline='#00AAAA', fill='#0000FF', width=5)
canvas.create_arc(10,300,400,200)
canvas.create_arc(10,300,400,200, start=45, extent=120)

ventana.mainloop()