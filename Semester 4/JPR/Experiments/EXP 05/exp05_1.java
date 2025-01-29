class exp05_1 {
    public static void main(String args[]) {
        System.out.println("Hello World");

        int[][] arr = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.println("arr[" + i + "][" + j + "]: " + arr[i][j]);
            }
        }
    }
}
