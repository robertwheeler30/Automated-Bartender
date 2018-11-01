from tkinter import *
from pourActions import pump_one,pump_two,pump_three,pump_four,pump_five,pump_six,pump_seven,pump_eight,pump_nine

window = Tk()
 
window.title("ANTON: Automated Bartender")
 
window.geometry('700x400')

window.configure(background='maroon')
 
lbl = Label(window, text="List of Drinks",fg = 'red')
 
lbl.grid(column=1, row=0)
 
btn1 = Button(window, text="Rum and Coke",command = pump_one,fg = 'purple')

btn1.grid(column=2, row=1)

btn2 = Button(window, text="Screwdriver",command = pump_two,fg = 'navy')
 
btn2.grid(column=3, row=2)

btn3 = Button(window, text="Long Island Ice Tea",command = pump_three,fg = 'navy')
 
btn3.grid(column=4, row=3)

btn4 = Button(window, text="Long Island Ice Tea",command = pump_three,fg = 'navy')
 
btn4.grid(column=5, row=4)
 
window.mainloop()