import sys

if len(sys.argv) != 2:
    print("You are missing a command-line arguments.")
    sys.exit(1)

print(f"Hello, {sys.argv[1]}")
sys.exit(0)