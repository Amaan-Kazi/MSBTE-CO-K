// exp07_2
class Box {
  int l, b, h;
  
  Box(int side) {
    l = side;
    b = side;
    h = side;
  }

  Box(int length, int breadth, int height) {
    l = length;
    b = breadth;
    h = height;
  }

  int volume() {
    return l * b * h;
  }

  public static void main (String args[]) {
    Box b1 = new Box(5);
    Box b2 = new Box(2, 8, 6);

    System.out.println("Box1(5) Volume: " + b1.volume());
    System.out.println("Box2(2, 8, 6) Volume: " + b2.volume());
  }
}
