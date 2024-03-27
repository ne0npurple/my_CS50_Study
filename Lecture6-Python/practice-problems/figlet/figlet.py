import sys
from pyfiglet import Figlet
import random

option = ["-f", "--font"]
fonts = []
figlet = Figlet()

for font in figlet.getFonts():
    fonts.append(font)
    
if len(sys.argv) == 1:
    fnt = random.choice(fonts)
elif len(sys.argv) == 3:
    if sys.argv[1] in option and sys.argv[2] in fonts:
        print("here")
        fnt = sys.argv[2]
    else:
        print("Invalid Usage")
        sys.exit(1)
else:
    print("Invalid Usage")
    sys.exit(1)

figlet.setFont(font=fnt)

text = input("Input: ")

print("Output:")
print(figlet.renderText(text))