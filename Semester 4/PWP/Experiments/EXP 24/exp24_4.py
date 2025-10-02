class Animal:
  def speak(self):
    print("Animal Speaking")

class Mammal(Animal):
  def drink_milk(self):
    print("Mammal Drinks Milk")

class Dog(Mammal):
  def bark(self):
    print("Dog Barks")

dog = Dog()
dog.speak()
dog.drink_milk()
dog.bark()
