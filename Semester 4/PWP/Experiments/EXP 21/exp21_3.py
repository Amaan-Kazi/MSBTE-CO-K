class Person:
  def __init__(self, name, age):
    self.name = name
    self.age  = age

  def display(self):
    print("Name:", self.name)
    print("Age: ", self.age, end="\n\n")

p1 = Person("Student 1", 20)
p2 = Person("Student 2", 18)

p1.display()
p2.display()
