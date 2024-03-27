# TODO
import cs50

counter = 0
change = 0
while change == None or change <= 0:
    change = cs50.get_float("Change owed: ")

if change != None and change > 0:
    change = change * 100 
    while change != None and change > 0:
        if change >= 25:
            change -= 25
        elif change >= 10:
            change -= 10
        elif change >= 5:
            change -= 5
        else:
            change -= 1
        counter += 1

print(counter)