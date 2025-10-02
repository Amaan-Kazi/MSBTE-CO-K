
# te = ()
# tn = (2, 6, 8, 10)
# tc = ('a', 'b', 'c', 'd')
# ts = ('a',)
# tString = tuple("Hello World")

# print(te)
# print(type(te))

# print(tn)
# print(type(tn))

# print(tc)
# print(type(tc))

# print(ts)
# print(type(ts))

# print(tString)
# print(type(tString))

t1 = (25, 100, 8, -8, 10, -200)
print("Tuple:", t1)
print("Type:", type(t1))
print("Length:", len(t1))
print("Minimum:", min(t1))
print("Maximum:", max(t1), end="\n\n")

t2 = tuple('Hello World')
print("Tuple:", t2)
print("Type:", type((t2)))
print("Index(W):", t2.index('W'))
print("Count(o):", t2.count('o'), end="\n\n")

for ch in t2:
  print(ch, ":", t2.count(ch))

# slicing of tuple
t3 = t2[1:6]
print(t3)
