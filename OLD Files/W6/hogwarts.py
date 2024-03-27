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
    # create a reader with a reader function from csv csv.reader() to read the file
    reader = csv.reader(file)
    # skip the first line in hogwarts.csv since it contains only title of "Timestamp,House"
    next(reader)
    #  iterate the row inside the file as defined "reader"
    for row in reader:
        #  define the house name by taking the row[1] only, since row[0] is the timestamp
        house = row[1]
        houses[house] += 1

#  print the counting result of each houses
for house in houses:
    count = houses[house]
    print(f"{house}: {count}")