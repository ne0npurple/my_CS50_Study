import csv

titles = {}

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["title"].strip().lower()
        if not title in titles:
            titles[title] = 0
        titles[title] += 1

#  create a function to get value of titles (the number counted) or use the lambda code as shown below to get the data without writing more code
# def get_value(title):
#     return titles[title]

# print out the title with the counted number sorted by the biggest value --> key: title, value: counter
# for title in sorted(titles, key=get_value, reverse=True):
#     print(title, titles[title])

# print out the title with its count by using key lambda to denote that this function is a function that won't be used anymore (it saves some lines of code by using the lambda)
for title in sorted(titles, key=lambda title: titles[title], reverse=True):
    print(title, titles[title])


