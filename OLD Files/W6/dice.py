import random

def check_input(input_strings):
    if input_strings in range(1,7):
        return input_strings
    else:
        print("Please insert number from 1-6")
        raise SystemExit(1)

def roll_dice(num_dice):
    roll_result = []
    for i in range(num_dice):
        roll = random.randint(1,6)
        roll_result.append(roll)
    return roll_result

num_dice_input = input("How many dice you want to roll? choose between 1-6 : ")
num_dice = check_input(int(num_dice_input))

# roll the dice
roll_result = roll_dice(num_dice)

print(roll_result)