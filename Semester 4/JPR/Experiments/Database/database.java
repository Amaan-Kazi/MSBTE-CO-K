import java.sql.*;

public class database {
    public static void main(String args[]) {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost/TESTING","root","");
            System.out.println("Database Connected");

            Statement query = conn.createStatement();

            query.execute("CREATE DATABASE TESTING");
            System.out.println("Database TEST Created");

            query.execute("CREATE TABLE CT1(RollNo INTEGER, Name TEXT(6), Marks INTEGER)");
            System.out.println("Created Table CT1");

            query.execute("INSERT INTO CT1 VALUES (1, 'Amaan', 100)");
            query.execute("INSERT INTO CT1 VALUES (2, 'Yash', 100)");
            query.execute("INSERT INTO CT1 VALUES (1, 'Shirish', 100)");
            System.out.println("Inserted Values");

            ResultSet result = query.executeQuery("SELECT * FROM CT1");
            while (result.next()) {
                System.out.println(result.getString(1) + " | " + result.getString(2) + " | " + result.getString(3));
            }

            // query.execute("DROP DATABASE TESTING");
        }
        catch (Exception e) {
            System.out.println(e);
        }
    }
}
