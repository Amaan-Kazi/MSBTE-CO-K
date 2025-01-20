class exp03_4 {
	public static void main (String args[]) {
		System.out.println("Using For Loop: ");
		for (int i = 1; i <= 20; i++) {
			System.out.println(i);
		}

		int i = 1;
		System.out.println("\nUsing While Loop: ");
		while (i <= 20) {
			System.out.println(i);
			i++;
		}

		i = 1;
		System.out.println("\nUsing Do While Loop: ");
		do {
			System.out.println(i);
			i++;
		} while (i <= 20);
	}
}
