from sys import argv, exit
import cs50

if len(argv) != 2:
    print("Usage: python roster.py House")
    exit(1)

db = cs50.SQL("sqlite:///students.db")

rows = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", argv[1])

for row in rows:
    if row['middle'] == None:
        print(f"{row['first']} {row['last']}, born {row['birth']}")
    else:
        print(f"{row['first']} {row['middle']} {row['last']}, born {row['birth']}")

