g = "hello"

greet = input("Greeting: ")
greet = greet.strip().lower()

if greet[:5] == g:
    print("$0")
else:
    print(greet[0])
    if greet[0] == 'h':
        print("$20")
    else:
        print("$100")