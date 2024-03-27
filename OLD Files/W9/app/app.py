from flask import Flask, render_template, request

# turn this file into flask application, __name__ define this app.py file
app = Flask(__name__)

# tell python to define a route of "/"
@app.route("/")
def index():
    # create a name arg
    return render_template("index.html")

# if we want to use POST method, writes as follow: --> USE request.form.get()
# meanwhile if we want to use GET method, use request.args.get()
@app.route("/greet", methods=["POST"])
def greet():
    name = request.form.get("name", "world")
    return render_template("greet.html", name=name)