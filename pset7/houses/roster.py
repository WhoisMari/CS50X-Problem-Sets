# TODO
import csv
import sqlite3
from sys import argv, exit

if len(argv) != 2: # Checks arguments
	print("Usage error, roster.py houseName")
	exit(1)

house = argv[1]

connector = sqlite3.connect("students.db") # Connect to db file
db = connector.cursor() # Create cursor

db.execute("SELECT first, middle, last, birth FROM students WHERE house = (?)", (house,))
students = db.fetchall()

for student in students: # Iterate through each student
	name = []
	name.append(student[0]) # Adds first name to variable

	if student[1] is not None: # Checks if student has middle name
		name.append(student[1]) # Adds it to variable

	name.append(student[2]) # Adds last name to variable
	birth = student[3] # Adds birth year to variable

	print(f"{' '.join(name)}, born {birth}") # Print each student name and birth year