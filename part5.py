from __future__ import print_function
from __future__ import division
import csv
import sys
import string 

import mysql.connector

print("Start part5.py")
# Fill this in with your own configuration values
config = {
  'user': 'root',
  'password': 'cs174$', 
  'host': '54.183.228.209', # connects to this host AWS
  'port': '3306', # Default port on Windows/Linux is 3306. On Mac it may be 3307.
  'database': 'project',
}

#make sure the sql server is running 
try:
  cnx = mysql.connector.connect(**config)
  cursor = cnx.cursor()
  print ("Successfully connected to server on AWS")
except mysql.connector.Error as err:
  print("Connection Error: {}".format(err))
  sys.exit(1)

#This is to read the file
def readInputFile(filename, function):
  #tries to open the file
  try:
    f = open(filename, 'r')
    userInput = f.read(256)
    print("UserInput from the file: ", userInput)
    #places values into function as values 
    function(userInput)
  #if can't open it then gives error
  except IOError as err:
    print("I/O Error: {}".format(err))

#This is what does all the inserting, selecting and stuff 
def emp_function(values):
  #prints the values that got passed from the file 
  print("Goes inside of emp_function")
  print ("File contents are: ", values)

  splitInput = values.split()
  length = len(splitInput)
  print ("Ths is the length of the command splitted: ", length)

  print ("This is the command: ", splitInput[0])
  #Insert row into the database 

  if (splitInput[0] == 'INSERT' or splitInput[0] == 'insert'):
    if (length == 4):
      """TO DO: CHECK IF ALREADY HAVE ID"""
      print("Got inside INSERT id age salary")
      """TO DO: PASS ON THE ENCRYPTED SALARY"""
      #insert_employee = ("INSERT INTO Employees VALUES""(%(id)s, %(age)s, %(salary)s)")

      """TO DO: IF ID ALREADY THERE THROW ERROR"""
   #   execute(insert_employee, values)
    else: 
      print ("Incorrect number of values")

  elif (splitInput[0] == 'SELECT' or splitInput[0] == 'select'):
    #if there's only SELECT emp_id
    if (length == 2):
      #second command 
      print("This is the second command: ", splitInput[1])
      if (splitInput[1] == '*'):
        print("Got inside SELECT *")
        """TO DO: PRINT OUT EVERYTHING"""
        #insert_employee = ("SELECT * FROM Employees")
      elif (splitInput[1].isdigit() == true):
        print("Got inside SELECT DIGIT")
        """TO DO: CHECK IF ID IN DATABASE"""
        #select_employee = ("SELECT ? FROM Employees", splitInput[2])
        #cursor.execute(select_employee, values)
        #for row in cursor: 
          #print row 

    elif (length == 3): 
      print("This is the second command, should be AVG: ", splitInput[1])
      if (splitInput[1] == 'AVG'):
        print("Got inside SELECT AVG salary")
        #sum_employee = ("SELECT SUM_HE(salary) FROM Employees") 
        #count_employee = ("SELECT COUNT (*) FROM Employees")
        #sum = execute(sum_employee, values)
        #count = execute(count_employee, values)
        #average= sum/count
        #print average

    elif (length == 4): 
      print("This is the second command, should be SUM or AVG: ", splitInput[1])
      print("This is the third command, should be WHERE : ", splitInput[2])
      if (splitInput[1] == 'SUM' and splitInput[2] == 'WHERE'): 
        print("Got inside SELECT SUM WHERE conditions")
        #select_employee = ("SELECT SUM_HE(salary) FROM Employees WHERE ?", splitInput[3]) 
        #result = execute(select_employee, values)
        #print result
      elif (splitInput[1] == 'AVG' and splitInput[2] == 'WHERE'):
        print("Got inside SELECT AVG WHERE conditions")
        #sum_employee = ("SELECT SUM_HE(salary) FROM Employees WHERE ?", splitInput[3]) 
        #count_employee = ("SELECT COUNT (*) FROM Employees WHERE ?", splitInput[3]")
        #sum = execute(sum_employee, values)
        #count = execute(count_employee, values)
        #average= sum/count
        #print average
      else: 
        print ("Incorrect input.")

    elif (length == 5): 
      print("This is the second command, should be SUM: ", splitInput[1])
      print("This is the third command, should be GROUP: ", splitInput[2])
      #checking if it actually splits the word GROUP BY
      print("This is the fourth command, should be BY: ", splitInput[3])
      #checking if it's grouping by age
      print("This is the fifth command, should be age: ", splitInput[4])     
      if (splitInput[1] == 'SUM' and splitInput[2]== 'GROUP' and splitInput[3]== 'BY' and splitInput[4]== 'age'): 
        print("Got inside SELECT SUM GROUP BY age")
        #select_employee = ("SELECT SUM_HE(salary) FROM Employees GROUP BY ?", splitInput[4]) 
        #result = execute(select_employee, values)
        #print result
      elif (splitInput[1] == 'AVG' and splitInput[2]== 'GROUP' and splitInput[3]== 'BY' and splitInput[4]== 'age'):
        print("Got inside SELECT AVG GROUP BY age")
        #sum_employee = ("SELECT SUM_HE(salary) FROM Employees WHERE ? GROUP BY age", splitInput[3]) 
        #count_employee = ("SELECT COUNT (*) FROM Employees WHERE ? GROUP BY age", splitInput[3]")
        #sum = execute(sum_employee, values)
        #count = execute(count_employee, values)
        #averageGroup= sum/count
        #print averageGroup
      else: 
          print ("Incorrect input.")
    elif (length == 7):
      print("This is the second command, should be SUM or AVG: ", splitInput[1])
      print("This is the third command, should be WHERE or GROUP: ", splitInput[2])
      print("This is the fourth command, should be BY or conditions if it was WHERE: ", splitInput[3])
      #checking if it actually splits the word GROUP BY
      print("This is the fourth command, should be GROUP or age: ", splitInput[4])
      print("This is the fifth command, should be BY or HAVING if only GROUP BY: ", splitInput[5])
      #checking if it's grouping by age
      print("This is the sixth command, should be BY or conditions if only GROUP BY: ", splitInput[6])
      if (splitInput[1] == 'SUM' and splitInput[2]== 'WHERE' and splitInput[4]== 'GROUP' and splitInput[5]== 'BY' and splitInput[6]== 'age'): 
        print("Got inside SELECT SUM WHERE conditions GROUP BY age")
        #select_employee = ("SELECT age, SUM_HE(salary) FROM Employees WHERE ? GROUP BY age", splitInput[3])
        #result = execute(select_employee, values)
        #print result
      elif(splitInput[1] == 'SUM' and splitInput[2]== 'GROUP' and splitInput[3]== 'BY' and splitInput[4]== 'age' and splitInput[5]== 'HAVING'):
        print("Got inside SELECT SUM GROUP BY age HAVING conditions")
        #select_employee = ("SELECT age, SUM_HE(salary) FROM Employees GROUP BY age HAVING ?", splitInput[6])
        #result = execute(select_employee, values)
        #print result
      elif(splitInput[1] == 'AVG' and splitInput[2]== 'GROUP' and splitInput[3]== 'BY' and splitInput[4]== 'age' and splitInput[5]== 'HAVING'):
        print("Got inside SELECT AVG GROUP BY age HAVING conditions")
        #sum_employee = ("SELECT SUM_HE(salary) FROM Employees GROUP BY age HAVING ?", splitInput[6]) 
        #count_employee = ("SELECT COUNT (*) FROM Employees GROUP BY age HAVING ?", splitInput[6])
        #sum = execute(sum_employee, values)
        #count = execute(count_employee, values)
        #averageGroup= sum/count
        #print averageGroupHav
      else: 
        print ("Incorrect input.")

    elif (length == 9):
      print("This is the second command, should be SUM: ", splitInput[1])
      print("This is the third command, should be WHERE: ", splitInput[2])
      #checking if it actually splits the word GROUP BY
      print("This is the fourth command, should be GROUP: ", splitInput[4])
      print("This is the fifth command, should be BY: ", splitInput[5])
      #checking if it's grouping by age
      print("This is the sixth command, should be age: ", splitInput[6])
      print("This is the seventh command, should be HAVING: ", splitInput[7])

      if (splitInput[1] == 'SUM' and splitInput[2]== 'WHERE' and splitInput[4]== 'GROUP' and splitInput[5]== 'BY' and splitInput[6]== 'age' and splitInput[7]== 'HAVING'): 
        print("Got inside SELECT SUM WHERE conditions GROUP BY age HAVING conditions")
        #select_employee = ("SELECT age, SUM_HE(salary) FROM Employees WHERE ? GROUP BY age HAVING ?", splitInput[3], splitInput[8])
        #result = execute(select_employee, values
        #print result
      elif(splitInput[1] == 'AVG' and splitInput[2]== 'WHERE' and splitInput[4]== 'GROUP' and splitInput[5]== 'BY' and splitInput[6]== 'age' and splitInput[7]== 'HAVING'):
        print("Got inside SELECT AVG WHERE conditions GROUP BY age HAVING conditions")
        #sum_employee = ("SELECT SUM_HE(salary) FROM Employees WHERE ? GROUP BY age HAVING ?", splitInput[3], splitInput[8]) 
        #count_employee = ("SELECT COUNT (*) FROM Employees WHERE ? GROUP BY age HAVING ?", splitInput[3], splitInput[8])
        #sum = execute(sum_employee, values)
        #count = execute(count_employee, values)
        #averageGroup= sum/count
        #print averageGroupHav
      else: 
        print ("Incorrect input.")
    else:
        print("Invalid arguments.")

if __name__ == '__main__':
  #readInputFile(filename, emp_function)
  readInputFile("userInput.txt", emp_function)
  #commit data 
  cnx.commit()

  cursor.close()
  cnx.close()


