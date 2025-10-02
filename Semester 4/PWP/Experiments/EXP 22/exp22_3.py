class Degree:
  def getDegree(self):
    print("I got a degree")

class UnderGraduate(Degree):
  def getDegree(self):
    print("I am an undergraduate")

class PostGraduate(Degree):
  def getDegree(self):
    print("I am a post graduate")

d = Degree().getDegree()
u = UnderGraduate().getDegree()
p = PostGraduate().getDegree()
