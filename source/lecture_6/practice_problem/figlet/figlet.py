from pyfiglet import Figlet
from sys import argv, exit


if len(argv) == 2:
    print("Invalid usage")
    exit(1)
elif len(argv) == 1:
    text = input("Input: ")
    f = Figlet()
    print(f.renderText(text))
    exit(0)
elif len(argv) == 3 and argv[1] in ["-f", "--font"]:
    allFonts = Figlet().getFonts()
    if argv[2] not in allFonts:
        print("Invalid usage")
        exit(1)
    text = input("Input: ")
    f = Figlet(font=argv[2])
    print(f.renderText(text))
    exit(0)
else:
    print("Invalid usage")
    exit(1)
