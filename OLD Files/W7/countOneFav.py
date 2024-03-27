import csv
# import regular expressions lib
import re

counter = 0 

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["title"].strip().upper()
        # search the title of "the office" movies using the regular expressions lib, here we can specify our pattern of the title that we want to search from the favorites.csv file since the users might have different kind of writing ex. the office, office, thevoffice.
        # "^" denotes the beginning of the input, "$" denotes the end of input, "." denotes any character
        if re.search("^OFFICE|THE.OFFICE$", title):
            counter += 1

print(f"The amount of people watching The Office are {counter}")