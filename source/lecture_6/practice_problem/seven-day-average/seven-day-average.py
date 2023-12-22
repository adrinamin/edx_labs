import csv
import requests
from csv import DictReader
from sys import exit

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
        
    # minor improvement
    if len(states) == 0:
        print("No states selected. Exiting.")
        exit(1)

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


def calculate(reader: DictReader[str]):
    nc = {} # state : list of new cases (max 14 days)
    previous = {} # state : each day's cases
    for row in reader:
        if row["state"] not in nc and row["state"] not in previous:
            nc[row["state"]] = []
            previous[row["state"]] = 0
            
        if len(nc[row["state"]]) < 14:
            nc[row["state"]].append(int(row["cases"]) - int(previous[row["state"]]))
        else:
            nc[row["state"]].pop(0)
            nc[row["state"]].append(int(row["cases"]) - int(previous[row["state"]]))
        previous[row["state"]] = int(row["cases"])
    
    # for testing purposes
    # print(f"Loaded {len(nc)} states.")
    # for state in nc:
    #     print(f"{state}: {nc[state]}")
        
    return nc


def comparative_averages(new_cases, states):
    for state in states:
        try:
            week1 = sum(new_cases[state][0:7]) / 7
            week2 = sum(new_cases[state][7:14]) / 7
            percent = (week2 - week1) / week1 * 100
            text = "increase" if (week2 - week1) > 0 else "decrease"
            print(f"{state} had a 7-day average of {week2:.2f} and an {text} of {abs(percent):.0f}%.")
        except ZeroDivisionError:
            print(f"{state} has no data. Division by zero error.")
            

main()
