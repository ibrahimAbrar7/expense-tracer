Program:1: Kabir runs a vehicle rental agency and maintains a CSV file named Rentals.csv. The file stores daily rental details with columns: Vehicle_ID, Vehicle_Type, Hours_Rented, Rate_Per_Hour Create the following user-defined functions:
I. AddRental() – to accept rental details from the user and append them to Rentals.csv.
II. CalculateTotalRent() – to calculate and return the total rent earned (Hours_Rented × Rate_Per_Hour)

import csv

def AddRental():
    Vehicle_ID = input("Enter Vehicle ID: ")
    Vehicle_Type = input("Enter Vehicle Type: ")
    Hours_Rented = input("Enter Hours Rented: ")
    Rate_Per_Hour = input("Enter Rate Per Hour: ")

    with open("Rentals.csv", "a") as f:
        w = csv.writer(f)
        w.writerow([Vehicle_ID, Vehicle_Type, Hours_Rented, Rate_Per_Hour])

    print("Rental record added successfully.")

def CalculateTotalRent():
    total = 0

    f = open("Rentals.csv", "r")
    r = csv.reader(f)

    for row in r:
        hours = int(row[2])
        rate = int(row[3])
        total += hours * rate

    print("Total Rent Earned:", total)
    f.close()


Program:2: Write a Python function capitalize_words(words) that takes a list of strings words and returns a new list with each word capitalize. Example: If the input is ["python", "computer", "science"] The output should be ["Python", "Computer", "Science"].

def capitalize_words(words):
    result = []

    for w in words:
        result.append(w.capitalize())

    print(result)


Program:: Write and call a Python function to read "History.txt" and display all lines that contain a four-digit year (e.g., 1999, 2024 etc.)

def DisplayYearLines():
    f = open("History.txt", "r")

    for line in f:
        words = line.split()

        for w in words:
            if w.isdigit() and len(w) == 4:
                print(line)
                break

    f.close()

DisplayYearLines()


Program: Write a Python function that displays the number of times the word "Python" appears in a text file named "Prog.txt"

def count_python():
    count = 0

    with open("Prog.txt", "r") as file:
        text = file.read()
        words = text.split()

        for word in words:
            if word.lower() == "python":
                count += 1

    print("The word Python appears", count, "times.")


Program: MySQL database named LibraryDB has a table book_records which contains the following attributes:
• Book_ID: ID of the book (Integer)
• Book_Title: Title of the book (String)
• Author: Author of the book (String)
• Copies: Number of copies available (Integer)

Consider the following details to establish Python-MySQL connectivity:
• Username: librarian
• Password: lib@2025
• Host: localhost

Program: Write a Python-MySQL program to change the Book_Title to 'Data Structures in Python' for the record whose Book_ID is 109 in the book_records table.

import mysql.connector

con = mysql.connector.connect(
    host="localhost",
    user="librarian",
    password="lib@2025",
    database="LibraryDB"
)

cur = con.cursor()

q = "UPDATE book_records SET Book_Title='Data Structures in Python' WHERE Book_ID=109"

cur.execute(q)
con.commit()

print("Book title updated successfully.")

cur.close()
con.close()

Program: Write a Python program using the random module to generate and display 5 random integers between 1 and 50.
import random

for i in range(5):
    print(random.randint(1, 50))

Program: 
import pickle

with open("marks.dat", "rb") as f:
    found = False

    try:
        while True:
            record = pickle.load(f)

            if record[0] == 20:
                print("Record:", record)
                found = True
                break

    except EOFError:
        pass

    if found == False:
        print("Roll no. not found")



import pickle
import os

def delete_record():
    rollno = int(input("Enter roll no. to delete: "))
    found = False

    try:
        with open("student.dat", "rb") as f, open("temp.dat", "wb") as temp:

            try:
                while True:
                    rec = pickle.load(f)

                    if rec[0] == rollno:
                        found = True
                    else:
                        pickle.dump(rec, temp)

            except EOFError:
                pass

        if found:
            os.replace("temp.dat", "student.dat")
            print("Record deleted successfully")
        else:
            os.remove("temp.dat")
            print("Record not found")

    except FileNotFoundError:
        print("File not found")

delete_record()


import pickle

with open("July.dat", "wb") as p:

    n = int(input("Enter total no. of students: "))

    for i in range(n):
        roll = int(input("Enter roll no. of student: "))
        name = input("Enter student's name: ")

        math = float(input("Enter Maths marks: "))
        phy = float(input("Enter Physics marks: "))
        chem = float(input("Enter Chemistry marks: "))
        cs = float(input("Enter CS marks: "))
        eng = float(input("Enter English marks: "))

        total = math + phy + chem + cs + eng
        per = (total / 500) * 100

        record = [roll, name, total, per]

        pickle.dump(record, p)

print("Record entry over")



import pickle
import os

rollno = int(input("Enter roll no. to modify: "))
found = False

try:
    with open("marks.dat", "rb") as f, open("temp.dat", "wb") as temp:

        try:
            while True:
                record = pickle.load(f)

                if record[0] == rollno:
                    found = True

                    print("Old Record:", record)

                    record[1] = input("Enter new name: ")
                    record[2] = float(input("Enter new marks: "))

                    print("Record modified successfully")

                pickle.dump(record, temp)

        except EOFError:
            pass

    if found:
        os.replace("temp.dat", "marks.dat")
    else:
        os.remove("temp.dat")
        print("Roll no. not found")

except FileNotFoundError:
    print("File not found")


import pickle

try:
    with open("marks.dat", "rb") as f:
        r = int(input("Enter the roll no. to be searched: "))
        found = False

        try:
            while True:
                record = pickle.load(f)

                if record[0] == r:
                    print("Record:", record)
                    found = True
                    break

        except EOFError:
            pass

        if found == False:
            print("Roll no. not found")

except FileNotFoundError:
    print("File not found")