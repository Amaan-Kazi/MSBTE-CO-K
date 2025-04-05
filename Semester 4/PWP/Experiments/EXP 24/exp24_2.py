class Student:
  def __init__(self, name, age):
    self.name = name
    self.age = age
  
  def display_info(self):
    print(f"Name: {self.name}, Age: {self.age}")

class CollegeStudent(Student):
  def __init__(self, name, age, course):
    Student.__init__(self, name, age)
    self.course = course

  def display_info(self):
    Student.display_info(self)
    print(f"Course: {self.course}")

s = CollegeStudent("Student", 24, "Computer Engineering")
s.display_info()
