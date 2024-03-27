import csv

name = input("Name: ")
house = input("House: ")

with open("hogwarts.csv", "a") as file:
    writer = csv.writer(file)
    writer.writerow([name, house])