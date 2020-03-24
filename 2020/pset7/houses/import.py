import csv
import cs50
import sys

open("students.db", "w").close()

db = cs50.SQL("sqlite:///students.db")

db.execute("CREATE TABLE students (first, middle, last, house, birth int)")

if len(sys.argv) != 2:
    print("Program should be executed with the name of the csv file")
    sys.exit()

characters = sys.argv[1]

with open(characters, "r") as file:

    reader = csv.reader(file)
    header = True
    for row in reader:
        if header:
            header = False
            continue
        name = row[0].split()
        house = row[1]
        birth = row[2]
        first = None
        middle = None
        last = None
        if len(name) == 3:
            first = name[0]
            middle = name[1]
            last = name[2]
        elif len(name) == 2:
            first = name[0]
            last = name[1]
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                    first, middle, last, house, int(birth))


