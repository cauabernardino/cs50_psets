from sys import argv, exit
import csv
import cs50

if len(argv) != 2:
    print("Usage: python import.py file.csv")
    exit(1)

open(f"students.db", "w").close()
db = cs50.SQL("sqlite:///students.db")

db.execute("""CREATE TABLE students (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    first VARCHAR(255),
    middle VARCHAR(255),
    last VARCHAR(255),
    house VARCHAR(10),
    birth INTEGER
    );""")

with open(argv[1], "r") as chars:
    reader = csv.DictReader(chars)

    names = []
    for row in reader:
        names = row['name'].split()

        if len(names) == 2:
            db.execute("INSERT INTO students (first, last, house, birth) VALUES(?, ?, ?, ?)",
                       names[0], names[1], row["house"], row["birth"])
        elif len(names) == 3:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       names[0], names[1], names[2], row["house"], row["birth"])