from cs50 import SQL
import sys
import csv

if len(sys.argv) != 2:
    print(f"Usage: {sys.argv[0]} FILE.csv")
    sys.exit(1)

db = SQL("sqlite:///roster.db")

# create table heads
db.execute('''CREATE TABLE IF NOT EXISTS heads (
    head_id INTEGER,
    head_name TEXT UNIQUE,
    PRIMARY KEY (head_id))''')

# create table houses
db.execute('''CREATE TABLE IF NOT EXISTS houses (
    house_id INTEGER,
    house_name TEXT UNIQUE,
    PRIMARY KEY (house_id),
    FOREIGN KEY (house_id) REFERENCES heads(head_id))''')

# create table students
db.execute('''CREATE TABLE IF NOT EXISTS Students (
    student_id INTEGER,
    student_name TEXT,
    house_id INTEGER,
    PRIMARY KEY(student_id),
    FOREIGN KEY (house_id) REFERENCES houses(house_id))''')

# if table exist, delete data to prevent duplicates
db.execute("delete from houses")
db.execute("delete from students")
db.execute("delete from heads")

with open(sys.argv[1], "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        name = row['student_name']
        house = row['house']
        head = row['head']
        # insert head
        db.execute('''INSERT OR IGNORE INTO heads (head_name) VALUES (?)''', head)
        
        # get head id
        head_id = db.execute('''SELECT head_id FROM heads WHERE head_name=?''', head)[0]["head_id"]
        
        # insert houses
        db.execute('''INSERT OR IGNORE INTO houses (house_id, house_name) VALUES (?, ?)''', head_id, house)
        
        # insert students
        db.execute('''INSERT INTO students (student_name, house_id) VALUES (?, ?)''', name, head_id)

