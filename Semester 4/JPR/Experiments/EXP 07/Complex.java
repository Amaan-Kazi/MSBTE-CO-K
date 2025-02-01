// exp07_5
import java.util.Scanner;

class Complex {
  int real;
  int imaginary;

  Complex(int r) {
    real = r;
    imaginary = 0;
  }

  Complex(int r, int i) {
    real = r;
    imaginary = i;
  }

  Complex add(Complex complex2) {
    return new Complex(real + complex2.real, imaginary + complex2.imaginary);
  }

  String display() {
    return "(" + real + "+" + imaginary + "i)";
  }

  public static void main (String args[]) {
    Scanner input = new Scanner(System.in);
    
    System.out.println("Complex 1: ");
    System.out.print("Real: ");
    int r = Integer.parseInt(input.nextLine());
    System.out.print("Imaginary: ");
    int i = Integer.parseInt(input.nextLine());
    Complex c1 = new Complex(r, i);

    System.out.println("\nComplex 2: ");
    System.out.print("Real: ");
    r = Integer.parseInt(input.nextLine());
    System.out.print("Imaginary: ");
    i = Integer.parseInt(input.nextLine());
    Complex c2 = new Complex(r, i);

    Complex addition = c1.add(c2);
    System.out.println("\n" + c1.display() + " + " + c2.display() + " = " + addition.display());

    input.close();
  }
}
