import java.sql.*;

public class exp28_1 {
  public static void main(String args[]) {
    try {
      Class.forName("com.mysql.jdbc.Driver");
      Connection conn = DriverManager.getConnection("jdbc:mysql://localhost/TEST","root","");
      // Statement query = conn.createStatement();

      // query.execute("CREATE TABLE Student (RollNo INTEGER, Name TEXT(20))");
      // System.out.println("Created Table STUDENT");

      // PreparedStatement ps = conn.prepareStatement("INSERT INTO STUDENT VALUES(?, ?)");
      // ps.setInt(1, 10);
      // ps.setString(2, "Amaan");
      // ps.execute();

      // PreparedStatement ps = conn.prepareStatement("DELETE FROM STUDENT WHERE RollNo = ?");
      // ps.setInt(1, 10);
      // ps.execute();

      // PreparedStatement ps = conn.prepareStatement("UPDATE STUDENT SET Name = ? WHERE RollNo = ?");
      // ps.setString(1, "Student 1");
      // ps.setInt(2, 10);
      // ps.execute();

      PreparedStatement ps = conn.prepareStatement("SELECT * FROM STUDENT");
      ResultSet rs = ps.executeQuery();

      while (rs.next()) {
        System.out.println("" + rs.getInt(1) + " | " + rs.getString(2));
      }
    }
    catch (Exception e) {
      System.out.println(e);
    }
  }
}
