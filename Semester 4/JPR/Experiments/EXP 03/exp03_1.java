import java.util.Scanner;

class exp03_1 {
	public static void main (String args[]) {
		Scanner input = new Scanner(System.in);

		System.out.print("Side 1: ");
		int s1 = Integer.parseInt(input.nextLine());

		System.out.print("Side 2: ");
		int s2 = Integer.parseInt(input.nextLine());

		System.out.print("Side 3: ");
		int s3 = Integer.parseInt(input.nextLine());

		// Check if sides create a real triangle
		if ( ((s1 + s2) < s3) || ((s2 + s3) < s1) || ((s1 + s3) < s2) ) {
			System.out.println("Invalid Triangle");
		}
		else {
			if (s1 == s2 && s2 == s3) {
				System.out.println("Equilateral Triangle");
			}
			else {
				if (s1 == s2 || s2 == s3 || s1 == s3) {
					System.out.println("Isoceles Triangle");
				}
				else {
					System.out.println("Scalene Triangle");
				}
			}
		}

		input.close();
	}
}
