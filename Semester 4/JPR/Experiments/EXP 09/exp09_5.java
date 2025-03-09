interface Area {
  double area();
}

class Rectangle implements Area {
  double l, b;

  Rectangle(double length, double breadth) {
    l = length;
    b = breadth;
  }

  public double area() {
    return l * b;
  }
}

class Circle implements Area {
  static double pi = 3.14;
  double r;

  Circle(double radius) {
    r = radius;
  }

  public double area() {
    return pi * r * r;
  }
}

class exp09_5 {
  public static void main(String args[]) {
    Rectangle r1 = new Rectangle(2, 10);
    Circle    c1 = new Circle(7);

    System.out.println("Rectangle Area: " + r1.area());
    System.out.println("Circle Area: " + c1.area());
  }
}
