d1 = {"Name": "Student", "RollNo": 25}
d2 = {"Class": "CO4K"}
d3 = {"Division": "B", "ClassNo": "P10"}

d4 = {**d1, **d2, **d3}
print(d4)
