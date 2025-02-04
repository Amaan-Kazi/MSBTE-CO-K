year = eval(input("Year: "))

if (year % 4 == 0) and not(year % 100 == 0) or (year % 400 == 0):
  print("The year is a leap year")
else:
  print("The year is a non leap year")
