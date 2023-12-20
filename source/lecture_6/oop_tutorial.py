"""
Notice that the meow function abstracts away the print statement. Further, notice that the main function appears at the top of the file. 
At the bottom of the file, the main function is called. By convention, it’s expected that you create a main function in Python.
"""

# Abstraction with parameterization

def main():
    meow(3)


# Meow some number of times
def meow(n):
    for i in range(n):
        print("meow")


main()

# Prints a column of bricks, catching exceptions

# def main():
#     height = get_height()
#     for i in range(height):
#         print("#")


# def get_height():
#     while True:
#         try:
#             n = int(input("Height: "))
#             if n > 0:
#                 return n
#         except ValueError:
#             print("Not an integer")


# main()


# Prints a column of 3 bricks with a loop

for i in range(3):
    print("#")

# Prints a row of 4 question marks with a loop

for i in range(4):
    print("?", end="")
print()

# Prints a row of 4 question marks without a loop (second variant)

print("?" * 4)

# Prints a 3-by-3 grid of bricks with loops

for i in range(3):
    for j in range(3):
        print("#", end="")
    print()



