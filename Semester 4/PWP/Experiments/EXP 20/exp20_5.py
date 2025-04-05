class Rectangle:
  def __init__(self, length, breadth):
    self.length = length
    self.breadth = breadth

  def area(self):
    return self.length * self.breadth
  
rect = Rectangle(5, 10)
print(rect.area())
