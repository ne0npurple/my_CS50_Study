# IMPLEMENTS: registration form; storing registrants to SQLite database; with support for deregistration; sending email to notify registrations

import os
import re

from cs50 import SQL
from flask import Flask, render_template, request, redirect
from flask_mail import Mail, Message

app = Flask(__name__)

# Requires that "Less secure app access" be on
# https://support.google.com/accounts/answer/6010255
app.config["MAIL_DEFAULT_SENDER"] = os.environ.get("MAIL_DEFAULT_SENDER")
app.config["MAIL_PASSWORD"] = os.environ.get("MAIL_PASSWORD")
app.config["MAIL_PORT"] = 587
app.config["MAIL_SERVER"] = "smtp.gmail.com"
app.config["MAIL_USE_TLS"] = True
app.config["MAIL_USERNAME"] = os.environ.get("MAIL_USERNAME")
mail = Mail(app)

SPORTS = [
    "Basketball",
    "Soccer",
    "Ultimate Frisbee"
]

# Create an empty dictionary to record value of registrants
# REGISTRANTS = {}

# the third / is to denote current folder
db = SQL("sqlite:///froshims.db")

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():

    # validate name
    name = request.form.get("name")
    if not name:
        return render_template("error.html", message="Missing input name!")
    
    #  validate email
    email = request.form.get("email")
    if not email:
        return render_template("error.hmtl", message="Missing input email!")

    #  validate sport
    sport = request.form.get("sport")
    if not sport:
        return render_template("error.html", message="Missing input sport!")
    if sport not in SPORTS:
        return render_template("error.html", message="Sport is invalid!")
    
    # record the registrants value to the dictionary:
    # REGISTRANTS[name] = sport

    db.execute("INSERT INTO registrants (name, email, sport) VALUES (?, ?, ? )", name, email, sport)

    # send email
    message = Message("You have successfuly registered!", recipients=[email])
    mail.send(message)

    # if all validation is passed, confirm registration
    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=registrants)


@app.route("/deregister", methods=["POST"])
def deregister():
    # get the id
    id = request.form.get("id")
    # validate and delete id if exist
    if id:
        db.execute("DELETE FROM registrants WHERE id=?", id)
    return redirect("/registrants")