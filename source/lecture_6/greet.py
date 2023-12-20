# Prints a command-line argument
import sys
from sys import argv

if len(argv) == 2:
    print(f"hello, {argv[1]}")
else:
    print("hello, world")
    
    
# Printing command-line arguments, indexing into argv
for i in range(len(argv)):
    print(argv[i])
    
    
# Printing command-line arguments using a slice
for arg in argv[1:]:
    print(arg)
    
    
# Exits with explicit value, importing sys
if len(sys.argv) != 2:
    print("Missing command-line argument")
    sys.exit(1)

print(f"hello, {sys.argv[1]}")
sys.exit(0)

