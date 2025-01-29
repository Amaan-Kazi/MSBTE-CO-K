import java.util.Vector;
import java.util.Scanner;

class exp05_3 {
  public static void main(String args[]) {
    Vector<Integer> vector = new Vector<>();
    Scanner input = new Scanner(System.in);

    System.out.println("Enter the 5 elements of vector:");

    for (int i = 0; i < 5; i++) {
      System.out.print("" + i + ": ");
      vector.add(Integer.parseInt(input.nextLine()));
    }

    System.out.println("\nDisplaying Vector:");
    for (int i: vector) {
      System.out.println(i);
    }

    input.close();
  }
}
