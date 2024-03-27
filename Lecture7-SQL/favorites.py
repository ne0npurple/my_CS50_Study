from cs50 import SQL

db = SQL("sqlite:///favorites.db")

fav = input("Favorites: ")

rows = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem=?", fav)

row = rows[0]
print(row['n'])