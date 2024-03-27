import csv

# create an empty list to store the new values after deleting duplicates
titles = []

# or use a set()
# titles = set()

# open the csv file in read "r" mode
with open("favorites.csv", "r") as file:
    # create a reader object from csv.reader /DictReader (this will skip the first line, and act as a dict)
    reader = csv.DictReader(file)
    # remove the duplicates and uppercase the letter of each title
    for row in reader:
        title = row["title"].strip().upper()
        # if using set() then just use the code below:
        # titles.add(title)
        if not title in titles:
            titles.append(title)
            
    
for title in sorted(titles):
    print(title)