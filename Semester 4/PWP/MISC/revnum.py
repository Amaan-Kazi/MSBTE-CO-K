num = int(input("Number: "))
rev = 0

temp = num % 10
num = num // 10
rev = (rev * 10) + temp

temp = num % 10
num = num // 10
rev = (rev * 10) + temp

temp = num % 10
num = num // 10
rev = (rev * 10) + temp

temp = num % 10
num = num // 10
rev = (rev * 10) + temp

print("Reverse:", rev)
