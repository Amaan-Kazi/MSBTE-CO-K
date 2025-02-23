num1 = eval(input("Num 1: "))
num2 = eval(input("Num 2: "))
num3 = eval(input("Num 3: "))

if (num1 >= num2) and (num1  >= num3):
  greater = num1
elif (num2 >= num1) and (num2 >= num1):
  greater = num2
else:
  greater = num3

print("Greater number: ", greater)
