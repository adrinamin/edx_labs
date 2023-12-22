import sys


menu = {
    "Baja Taco": 4.25,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

print("Welcome to felipe's Taqueria! Please choose an item from the menu.")
print("Exit by pressing Ctrl+D.")

total = 0.00

while True:
    try:
        item = input("Item: ").title()
    except EOFError:
        print("Ctrl+D detected. Exiting...")
        sys.exit(0)

    if item in menu.keys():
        total = total + menu[item]
        print(f"Price: ${total:.2f}")
    else:
        print("Sorry, that item is not on the menu.")