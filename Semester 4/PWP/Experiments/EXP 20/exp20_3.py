import roman

class RomanConverter:
  def __init__(self, num):
    self.num = num
  
  def toRoman(self):
    return roman.toRoman(self.num)
  
r = RomanConverter(58)
print(r.toRoman())
