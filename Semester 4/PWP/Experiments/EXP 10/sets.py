# s1 = set()
# s2 = {}
# s3 = { 10, 20, 30, 40, 50 }

# l1 = [50, 100, 150, 200, 250]
# s4 = set(l1)

# t1 = (1000, 2000, 3000, 4000, 5000)
# s5 = set(t1)

# print(s1)
# print(type(s1), end="\n\n")

# print(s2)
# print(type(s2), end="\n\n")

# print(s3)
# print(type(s3), end="\n\n")

# print(s4)
# print(type(s4), end="\n\n")

# print(s5)
# print(type(s5))



# s1 = { 10, 20, 30, 40, 50 }
# print(6 not in s1)
# print(10 not in s1)
# print(50 in s1)
# print(100 in s1)

# s1.add(200)
# print(s1)


# print(s1.issubset({20, 30, 40}))

# s1.remove(20)
# print(s1)

# s1.clear()
# print(s1)

s1 = {1, 2, 3, 4}
s2 = {1, 2, 3, 4, 5, 6, 7}
# print(s1.issubset(s2))
# print(s2.issuperset(s1))
# print(s1)
# print("Length:", len(s1))
# print("Minimum:", min(s1))
# print("Maximum:", max(s1))

print(s1.union(s2))
print(s1 | s2)

print(s1.intersection(s2))
print(s1 & s2)

print(s2.difference(s1))
print(s2 - s1)
