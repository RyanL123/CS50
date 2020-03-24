import sys
import cs50

open("students.db", "r").close()

db = cs50.SQL("sqlite:///students.db")

if len(sys.argv) != 2:
    print("Program should be executed with the name of a house")
    sys.exit()

house = sys.argv[1]

results = db.execute("SELECT first, middle, last, birth FROM students WHERE house=? ORDER BY last, first", house)

for student in results:
    first = student["first"]
    middle = student["middle"]
    last = student["last"]
    birth = student["birth"]
    if middle:
        print(f"{first} {middle} {last}, born {birth}")
    else:
        print(f"{first} {last}, born {birth}")