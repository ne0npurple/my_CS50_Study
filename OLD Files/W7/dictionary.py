import csv

newDict = {}

# with open("hogwarts.csv", "r") as file:
#     reader = csv.DictReader(file)
#     for row in reader:
#         name = row["Name"]
#         house = row["House"]
#         if not name in newDict:
#             newDict[name] = house

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["title"].lower()
        genres = row["genres"].lower()
        if not title in newDict:
            newDict[title] = 0
        newDict[title] += 1

print(newDict)