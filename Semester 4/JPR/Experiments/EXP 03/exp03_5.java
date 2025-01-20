class exp03_5 {
	public static void main (String args[]) {
		int i = 0;
		int j = 0;

		do {
			System.out.println("i: " + i + " j: " + j);
			i += 1;
			j += 2;
		} while (i < j && !(j > 20 || i > 10));
	}
}
