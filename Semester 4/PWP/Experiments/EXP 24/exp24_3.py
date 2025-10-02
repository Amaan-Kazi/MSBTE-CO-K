class Book:
  def title(self):
    print("Title of the book")

class Author:
  def author_name(self):
    print("Author Name")

class FictionBook(Book, Author):
  def genre(self):
    print("Fiction")

fiction = FictionBook()
fiction.title()
fiction.author_name()
fiction.genre()
