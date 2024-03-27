scores = []

while len(scores) < 3:
    try:
        num = int(input("Score: "))
        scores.append(num)
    except ValueError:
        print("Not an integer.")

average = sum(scores)/len(scores)
print(f"Average: {average}")