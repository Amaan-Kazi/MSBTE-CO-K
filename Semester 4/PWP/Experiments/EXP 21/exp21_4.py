class Student:
  def __init__(self, name = "Unknown", age = None, grade = None):
    self.name  = name
    self.age   = age
    self.grade = grade

  def display(self):
    print(f"Name: {self.name} | Age: {self.age if self.age is not None else "Not Provided"} | Grade: {self.grade if self.grade is not None else "Not Provided"}")

s1 = Student().display()
s2 = Student("Student 1").display()
s3 = Student("Student 2", 20).display()
s4 = Student("Student 3", 25, 80).display()

