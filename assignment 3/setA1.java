import java.sql.*;
import java.io.*;
class setA1 {
	public static void main(String[] args) throws SQLException{
		Connection con = null;
		Statement stmt = null;
		ResultSet rs = null;
		//try{
			//Class.forName("org.postgresql.Driver");
			con = DriverManager.getConnection("jdbc:192.168.100.10:tybcs3","tybcs3","");
			if(con==null){
				System.out.println("Connection failed");
			}else{
				System.out.println("Connection successfull");
				/*stmt = con.createStatement();
				rs = stmt.executeQ*/
			}
		
		}
	
	//}

}
