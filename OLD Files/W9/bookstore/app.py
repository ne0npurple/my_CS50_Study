from flask import Flask, render_template, request, redirect, session
from cs50 import SQL
from flask_session import Session

#  configure flask
app = Flask(__name__)

#  connect to database
db = SQL("sqlite:///store.db")

#  configure session
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# display the index page with all the available books 
@app.route("/")
def index():
    books = db.execute("SELECT * FROM books")
    return render_template("books.html", books=books)

# the cart in which each users is use to add their favorite books
@app.route("/cart")
def cart():

    # ensure "cart" exists:
    if "cart" not in session:
        session["cart"] = []

    # handle POST request
    if request.method == "POST":
        id = request.form.get("id")
        if id:
            session["cart"].append(id)
    return redirect("/cart")

    # handle GET request
    books = db.execute("SELECT * FROM books WHERE id IN (?)", session["cart"])
    return render_template("cart.html", books=books)