height = eval(input("Height: "))

digits = 1
for i in range(1, height):
  digits += 2

for i in range(0, height):
  is1 = True

  for j in range(i):
    print(" ", end="")

  for j in range(digits):
    if is1: print("1", end="")
    else  : print("0", end="")
    is1 = not(is1)
  
  digits -= 2
  print(" ")


for i in range(height):
  for j in range(height - i - 1):
    print(" ", end="")
  for j in range(2 * i + 1):
    print("*", end="")
  print()

for i in range(height - 2, -1, -1):
  for j in range(height - i - 1):
    print(" ", end="")
  for j in range(2 * i + 1):
    print("*", end="")
  print()
