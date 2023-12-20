import csv

# create a csv file
with open("test.csv", "w") as csvfile:
    writer = csv.DictWriter(csvfile, fieldnames=["id", "name", "age"]) # fieldnames is the first line of the csv file
    # data
    writer.writerow({"id":"10001", "name": "Mike", "age": 20})
    writer.writerow({"id":"10002", "name": "Bob", "age": 22})
    writer.writerow({"id":"10003", "name": "Jordan", "age": 21})