class Shape:
  def area(self, *args):
    if len(args) == 1:
      side = args[0]
      print(side * side)
    elif len(args) == 2:
      length, breadth = args
      print(length * breadth)
    else:
      print("Invalid")

s = Shape()
s.area(10)
s.area(2, 20)
s.area(2, 10, 5)
