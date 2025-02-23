num = int(input("Enter a number: "))
fact = 1

for i in range(2, num + 1):
  fact = fact * i

print("Factorial:", fact)
