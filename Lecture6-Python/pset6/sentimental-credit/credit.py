# TODO
import cs50
import math

def main():
    number = cs50.get_string("Number: ")
    
    if number != None and len(number) <= 10:
        return "INVALID"
    
    if (number != None and is_card(number) == True):
        if int(number[0]) == 3 and (int(number[1]) == 4 or int(number[1]) == 7):
            return "AMEX"
        elif int(number[0]) == 4:
            return "VISA"
        elif int(number[0]) == 5 and (int(number[1]) == 1 or int(number[1]) == 2 or int(number[1]) == 3 or int(number[1]) == 4 or int(number[1]) == 5):
            return "MASTERCARD"
        else:
            return "INVALID"
    else:
        return "INVALID"

def is_card(number):
    rightsum = get_right_sum(number)
    leftsum = get_left_sum(number)
    if ((rightsum + leftsum) % 10) == 0:
        return True
    return False

def get_right_sum(number):
    rightsum = 0
    idx = len(number)-2
    while idx >= 0:
        num = 2* int(number[idx])
        while num != 0:
            rightsum += num % 10
            num = math.floor(num / 10)
        idx -= 2
    return rightsum

def get_left_sum(number):
    leftsum = 0
    idx = len(number)-1
    while idx >= 0:
        leftsum += int(number[idx])
        idx -= 2
    return leftsum
    
print(main())