import sys

height = 0

while height < 1 or height > 8:
    try:
        print("Height: ", end="")
        height = int(input())
    except ValueError:
        continue
    except KeyboardInterrupt:
        print()
        print("Exited by user")
        sys.exit(0)
    except EOFError:
        print()
        print("Exited by user")
        sys.exit(0)

for i in range(height):
    for j in range(height - i - 1):
        print(" ", end="")
        
    for k in range(i + 1):
        print("#", end="")
    
    print("  ", end="")
    
    for l in range(i + 1):
        print("#", end="")
    print()