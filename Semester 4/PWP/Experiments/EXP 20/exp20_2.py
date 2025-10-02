class StringReversal:
  def reverse(self, string):
    words = string.split(" ")
    rev_string = ""

    for word in words:
      rev_string += "".join(reversed(word))
      rev_string += " "
    
    return rev_string
  
s = StringReversal()
print(s.reverse("Hello World ABC 123"))
