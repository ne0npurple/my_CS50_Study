def main():
    height = get_height()
    for i in range(height):
        print("#", end="")
    print()

def get_height():
    while True:
        try:
            height = int(input("Height: "))
            if height > 0:
                return height
        except ValueError:
            print("Not an integer.")
    
main()