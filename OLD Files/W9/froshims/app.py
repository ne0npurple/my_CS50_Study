from flask import Flask, render_template, request

app = Flask(__name__)

SPORTS = [
    "Basketball",
    "Soccer",
    "Ultimate Frisbee"
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    #  do some validation to see whether if the user input the name and the sport
    if not request.form.get("name") or request.form.get("sport") not in SPORTS:
        return render_template("failure.html")
    
    # if validation success then go to this page
    return render_template("success.html")
