
from tkinter import *
from pourActions import pump_one, pump_two, pump_three, pump_four, pump_five, pump_six, pump_seven, pump_eight, pump_nine
ingreds = []

root = Tk()
root.title("ANTON: Hardware Config")

# Add a grid
mainframe = Frame(root)
mainframe.grid(column=0, row=0, sticky=(N, W, E, S))
mainframe.columnconfigure(0, weight=1)
mainframe.rowconfigure(0, weight=1)
mainframe.pack(pady=100, padx=100)

# Create a Tkinter variable
tkvar = StringVar(root)
choices = {'rum', 'coke', 'vodka', 'orange juice'}
tkvar.set('Select a Mixer')  # set the default option

popupMenu = OptionMenu(mainframe, tkvar, *choices)

p_lbl = Label(mainframe, text = "Select a Mixer for Pump "

# link function to change dropdown
tkvar.trace('w', change_dropdown)

root.mainloop()