# TODO
import csv
import sqlite3
from sys import argv, exit

if len(argv) != 2:
	print("Usage error, import.py characters.csv")
	exit(1)

filename = argv[1]
connector = sqlite3.connect("students.db") # Connect to db file

db = connector.cursor() # Create cursor

with open(argv[1], "r") as students: # Opens csv
	reader = csv.DictReader(students) # Create dictionary

	for row in reader: # Iterate through each row
		student = [] # Create student empty list

		for name in row['name'].split(): # Iterate through each part of the name (first, middle, and last)
			student.append(name)

		student.append(row["house"])
		student.append(row["birth"])

		if (len(student) == 5): # Checks student list length
			db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", student[:5])

		if (len(student) == 4):
			db.execute("INSERT INTO students (first, last, house, birth) VALUES(?, ?, ?, ?)", student[:4])