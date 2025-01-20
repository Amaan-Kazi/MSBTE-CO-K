class exp04_1 {
    public static void main (String args[]) {
        String str = new String("Hello World");
	String str2 = new String("hEllO worLd");

	System.out.println("1. charAt(2):       " + str.charAt(2) );
	System.out.println("2. length():        " + str.length() );
	System.out.println("3. substring(2):    " + str.substring(2) );
	System.out.println("4. substring(2, 9): " + str.substring(2, 9) );
	System.out.println("5. equals(str2):    " + str.equals(str2) );
    }
}
