import tkinter as tk
from drinkList import drink_options

class App():
    def __init__(self, parent):
        self.parent = parent
        self.options = drink_options

        self.om_variable = tk.StringVar(self.parent)
        self.om_variable.set(self.options[0])
        self.om_variable.trace('w', self.option_select)

        self.om = tk.OptionMenu(self.parent, self.om_variable, *self.options)
        self.om.grid(column=0, row=0)

        self.update_button = tk.Button(
            self.parent, text='Update option menu', command=self.update_option_menu)
        self.update_button.grid(column=0, row=2)

    def update_option_menu(self):
        menu = self.om["menu"]
        menu.delete(0, "end")
        for string in self.options:
            menu.add_command(label=string,
                             command=lambda value=string: self.om_variable.set(value))

    def add_option(self):
        self.options.append(self.entry.get())
        self.entry.delete(0, 'end')
        print(self.options)

    def option_select(self, *args):
        print(self.om_variable.get())


root = tk.Tk()
App(root)
root.mainloop()
