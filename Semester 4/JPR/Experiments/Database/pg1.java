import java.sql.*;

class pg1
{
public static void main(String args[])
{
try
{
	Class.forName("com.mysql.jdbc.Driver");
	Connection c=DriverManager.getConnection("jdbc:mysql://localhost/dbtest2","root","");
	System.out.println("DONE");
	
	Statement s=c.createStatement();
	// s.execute("CREATE DATABASE TEST1");
	// System.out.println("DATABASE CREATED");

	s.execute("create table CT1(name text(16),surname text(6),marks INTEGER)");
	System.out.println("Table created");


	//s.execute("insert into CT1(name,surname,marks) values('Sameer','Pednekar',85)");
	//System.out.println("Value added");

	//s.execute("update CT1 SET name='Pratibha' WHERE marks=85");
	//System.out.println("Value updated");

	//s.execute("delete from CT1 WHERE marks=85");
	//System.out.println("Value deleted");

	// ResultSet rs=s.executeQuery("select * from CT1");
	// while(rs.next())
	// System.out.println(rs.getString(1));


}
catch(Exception e)
{
	System.out.println(e);
}
}
}
