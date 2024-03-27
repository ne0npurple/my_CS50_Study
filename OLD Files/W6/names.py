import sys

names = ["Lin", "Jason", "Barry", "Charlie"]

if "Joe" in names:
    print("Found")
    sys.exit(0)

print("Not found")
sys.exit(1)