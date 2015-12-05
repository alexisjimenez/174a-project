from __future__ import print_function
import csv
import sys
import string 

import mysql.connector

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

  #compare the first word to the keywords to check what to do 
  command = values.split()[:1]
  print ("This is the command: ", command)
  listToS = ''.join(command)
  print("This is the first command as a string: ", listToS)

  #Insert row into the database 
  if (listToS == 'INSERT' or listToS == 'insert'):
    if (length == 4):
      """TO DO: CHECK IF ALREADY HAVE ID"""
      print("Got inside INSERT")
      """TO DO: PASS ON THE ENCRYPTED SALARY"""
      #insert_employee = ("INSERT INTO Employees VALUES""(%(id)s, %(age)s, %(salary)s)")

      """TO DO: IF ID ALREADY THERE THROW ERROR"""
   #   execute(insert_employee, values)
    else: 
      print ("Incorrect number of values")

  elif (listToS == 'SELECT' or listToS == 'select'):
    #if there's only SELECT emp_id
    if (length == 2):
      #second command 
      secCommand = values.split()[1]
      seclistToS = ''.join(secCommand)
      print("This is the second command as a string: ", seclistToS)

      if (seclistToS == '*'):
        print("Got inside SELECT *")
        """TO DO: PRINT OUT EVERYTHING"""
        #insert_employee = ("SELECT * FROM Employees")
      elif (seclistToS.isdigit() == true):
        """TO DO: CHECK IF ID IN DATABASE"""
        #select_employee = ("SELECT id FROM Employees") 
        #result = execute(select_employee, values)
        #print result
      
        #if (thirdlistToS == 'WHERE'): 

        #elif (thirdlistToS == 'GROUP BY')

       # elif (fifthlistToS == 'GROUP BY')
      #else: 


if __name__ == '__main__':
  #readInputFile(filename, emp_function)
  readInputFile("userInput.txt", emp_function)
  #commit data 
  cnx.commit()

  cursor.close()
  cnx.close()
