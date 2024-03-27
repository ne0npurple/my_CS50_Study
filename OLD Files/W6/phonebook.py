people = {
    "Lin" : "+6282282171770",
    "Jason" : "+886979021898"
}

name = input("Search person: ")
if name in people:
    print(f"phone number : {people[name]}")