import java.sql.*;

public class exp27_1 {
  public static void main(String args[]) {
    try {
      Class.forName("com.mysql.jdbc.Driver");
      Connection conn = DriverManager.getConnection("jdbc:mysql://localhost/TEST","root","");
      Statement query = conn.createStatement();

      query.execute("CREATE TABLE STUDENT (RollNo INTEGER, Name TEXT(6), Marks INTEGER)");
      System.out.println("Created Table STUDENT");

      query.execute("INSERT INTO STUDENT VALUES (1, 'Student', 100)");
      System.out.println("Inserted Values");
    }
    catch (Exception e) {
      System.out.println(e);
    }
  }
}
