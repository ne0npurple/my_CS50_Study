import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    new_case = dict()
    prev_case = dict()
    for row in reader:
        key = row['state']
        val = int(row['cases'])
        oldval = val
        if key not in new_case.keys():
            new_case[key] = []
            prev_case[key] = []
        if len(new_case[key]) > 0:
            val = val - prev_case[key]
            if len(new_case[key]) >= 14:
                del new_case[key][0]
        new_case[key].append(val)
        prev_case[key] = oldval
    return new_case

# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        prevweek_avg = round(sum(new_cases[state][:7])/7)
        latestweek_Avg = round(sum(new_cases[state][7:])/7)
        
        diff = (latestweek_Avg-prevweek_avg)
        if diff < 0:
            diff *= (-1)
            desc = 'a decrease of'
        else:
            desc = 'an increase of'

        try:
            percentage = round((diff/prevweek_avg) * 100)
        except ZeroDivisionError:
            raise ZeroDivisionError
        
        print(f"{state} had a 7-day average of {latestweek_Avg} and {desc} of {percentage}%")

main()
