class StringManipulator:
  def __init__(self):
    self.string = ""

  def get_string(self):
    self.string = input("Enter String: ")
  
  def print_string(self):
    print(self.string.upper())

s = StringManipulator()
s.get_string()
s.print_string()
