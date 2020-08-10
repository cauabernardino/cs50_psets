from sys import argv, exit
import csv

if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

db = argv[1]
sequence = argv[2]

rows = []

with open(db, "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        rows.append(dict(row))

keys = list(rows[0].keys())
keys.remove('name')

with open(sequence, "r") as file:
    dna = file.read()

count = {}.fromkeys(keys, 1)


for STR in keys:
    for i in range(len(dna)):
        if dna[i:i+len(STR)] == STR:
            if dna[i-len(STR):i] == dna[i:i+len(STR)]:
                count[STR] += 1
        if i+len(STR) == len(dna)-1:
            pass


candidate = ['name', 0]
n = 0
for i in rows:
    for STR in keys:
        if int(count[STR]) == int(i[STR]):
            n += 1
    if n > candidate[1]:
        candidate[0] = i['name']
        candidate[1] = n
    n = 0

if candidate[1] < len(keys) - 1:
    print('No match')
else:
    print(candidate[0])