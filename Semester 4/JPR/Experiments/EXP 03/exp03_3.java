import java.util.Scanner;

class exp03_3 {
	public static void main (String args[]) {
		Scanner input = new Scanner(System.in);

		System.out.print("Num1: ");
		int num1 = Integer.parseInt(input.nextLine());

		System.out.print("Num2: ");
		int num2 = Integer.parseInt(input.nextLine());


		System.out.print("Operator: ");
		char operator = input.nextLine().charAt(0);

		switch (operator) {
			case '+':
				System.out.println("" + num1 + " + " + num2 + " = " + (num1 + num2));
				break;
			case '-':
				System.out.println("" + num1 + " - " + num2 + " = " + (num1 - num2));
				break;
			case '*':
				System.out.println("" + num1 + " * " + num2 + " = " + (num1 * num2));
				break;
			case '/':
				System.out.println("" + num1 + " / " + num2 + " = " + (num1 / num2));
				break;
			case '%':
				System.out.println("" + num1 + " % " + num2 + " = " + (num1 % num2));
				break;
			default:
				System.out.println("Invalid");
				break;
		}

		input.close();
	}
}
