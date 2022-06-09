from csv import reader, DictReader
from sys import argv

if len(argv) != 3:
    print("Usage error, dna.py sequence.txt database.csv")
    exit()


with open(argv[2]) as dna_file: # Opens csv
    dna_reader = reader(dna_file) # Creates dictionary

    for row in dna_reader: # Iterate through each row
        dna_list = row

dna = dna_list[0]
sequences = {}

with open(argv[1]) as people_file:
    people = reader(people_file)

    for row in people:
        dna_sequences = row
        dna_sequences.pop(0)
        break

for item in dna_sequences:
    sequences[item] = 1

for key in sequences:
    l = len(key)
    tempMax = 0
    temp = 0
    for i in range(len(dna)):
        while temp > 0:
            temp -= 1
            continue
        
        if dna[i: i + l] == key:
            while dna[i - l: i] == dna[i: i + l]:
                temp += 1
                i += l
            
        if temp > tempMax:
            tempMax = temp
        
    sequences[key] += tempMax

with open(argv[1], newline='') as people_file:
    people = DictReader(people_file)
    for person in people:
        match = 0
        
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1
        if match == len(sequences):
            print(person['name'])
            exit()
    
    print("No match")