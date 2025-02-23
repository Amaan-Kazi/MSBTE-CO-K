num = int(input("Enter the number of terms: "))
a = 0
b = 1
count = 0

while count < num:
  print(a, end=" ")
  
  a_new = a + b
  a = b
  b = a_new

  count += 1
