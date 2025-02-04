month = eval(input("Number of Month: "))

if (month == 2):
  year = eval(input("Year: "))
  if (year % 4 == 0) and not(year % 100 == 0) or (year % 400 == 0):
    print("The month has 29 days")
  else:
    print("The month has 28 days")
elif (month == 1, 3, 5, 7, 8, 10, 12):
  print("The month has 31 days")
elif (month == 4, 6, 9, 11):
  print("The month has 30 days")
else:
  print("Invalid Month")
