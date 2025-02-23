english = eval(input("English: "))
hindi   = eval(input("Hindi: "))
maths   = eval(input("Maths: "))
science = eval(input("Science: "))
history = eval(input("History: "))

percentage = (english + hindi + maths + science + history) / 5

if (percentage >= 90):
  print("Grade A")
elif (percentage >= 80):
  print("Grade B")
elif (percentage >= 70):
  print("Grade C")
else:
  print("Grade D")
