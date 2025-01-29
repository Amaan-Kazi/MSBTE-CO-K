// exp07_1
class Rectangle {
  int l, b;

  Rectangle(int side) {
    l = side;
    b = side;
  }

  Rectangle(int length, int breadth) {
    l = length;
    b = breadth;
  }

  int area() {
    return l * b;
  }

  
  public static void main(String args[]) {
    Rectangle r1 = new Rectangle(5);
    Rectangle r2 = new Rectangle(25, 2);

    System.out.println("Rectangle 1 Area: " + r1.area());
    System.out.println("Rectangle 2 Area: " + r2.area());
  }
}
