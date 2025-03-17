from collections import Counter

d1 = {
    'a': 100,
    'b': 200,
    'c': 300
}
print(d1)

d2 = {
    'a': 300,
    'b': 200,
    'c': 400
}
print(d2)

d3 = Counter(d1) + Counter(d2)
print(d3)
