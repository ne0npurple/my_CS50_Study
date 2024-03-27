import csv

# create an empty dictionary to count each of the house in Harry Potter
houses = {
    "Gryffindor" : 0,
    "Hufflepuff" : 0,
    "Ravenclaw" : 0,
    "Slytherin" : 0,
}

# open the file in read mode only
with open("hogwarts.csv", "r") as file:
    # create a reader with DictReader() function to read the second line of the csv file automatically
    reader = csv.DictReader(file)
    #  iterate the row inside the file as defined "reader"
    for row in reader:
        #  define the house name by taking the title inside csv file that we want to take, this time it's called "House" --> check in hogwarts.csv
        house = row["House"]
        #  start counting the house
        houses[house] += 1

#  print the counting result of each houses
for house in houses:
    count = houses[house]
    print(f"{house}: {count}")