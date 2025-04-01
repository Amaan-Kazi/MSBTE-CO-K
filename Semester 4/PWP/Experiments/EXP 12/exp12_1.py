my_diet = {
  "Apple": 3,
  "Banana": 1,
  "Orange": 2,
  "Watermelon": 1
}

# Ascending
print(dict( sorted(my_diet.items()) ))
print(dict( sorted(my_diet.items(), key=lambda item:item[1]) ))

# Descending
print(dict( sorted(my_diet.items(), reverse=True) ))
print(dict( sorted(my_diet.items(), reverse=True, key=lambda item:item[1]) ))
