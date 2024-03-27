import sys

names = ["Lin", "Jason", "Adel", "Nindy"]

name = input("Name: ")

if name in names:
    print("Found.")
    sys.exit(0)
else:
    print("Not found.")
    sys.exit(1)