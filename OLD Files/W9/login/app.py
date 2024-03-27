from flask import Flask, redirect, render_template, request, session
from flask_session import Session

#  configure app
app = Flask(__name__)

# configure session
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    # check if the user has login, session must be exist if a user has previously login
    if not session.get("name"):
        return redirect("/login")
    return render_template("index.html")

# methods used are post and get, get is used when the user open the path blabla.../login in their website
@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        session["name"] = request.form.get("name")
        return redirect("/")
    return render_template("login.html")

@app.route("/logout")
def logout():
    session["name"] = None
    return redirect("/")