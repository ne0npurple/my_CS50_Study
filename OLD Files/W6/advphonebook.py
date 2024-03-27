import csv

# common version

# file = open("phonebook.csv", "a")

# name = input("Insert name: ")
# number = input("Phone number: ")

# writer = csv.writer(file)
# writer.writerow([name, number])

# file.close()



## code in optimized version

name = input("Name: ")
number = input("Number: ")

#  the "with" function will help to close file as in file.close() automatically
with open("phonebook.csv", "a") as file:
    writer = csv.writer(file)
    writer.writerow([name, number])