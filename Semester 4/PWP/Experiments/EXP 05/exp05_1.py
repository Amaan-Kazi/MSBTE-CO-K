num = eval(input("Number: "))
oNum = num
rev = 0

while (num != 0):
  temp = num % 10
  num = num // 10
  rev = (rev * 10) + temp

if (oNum == rev):
  print("Number is a pallindrome")
else:
  print("Number is not a pallindrome")
