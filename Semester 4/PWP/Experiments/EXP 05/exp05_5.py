num = eval(input("Number: "))
rev = 0

while (num != 0):
  temp = num % 10
  num = num // 10
  rev = (rev * 10) + temp
