import java.sql.*;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

public class Q1{
	public static void main(String[] args){
		JFrame f;
		JTable t;
		int id = 0;
		
		f= new JFrame();
		f.setTitle("Project Details ");
		
		String[] Colm= {"Project_ID","Project_Name","Project_Description","Project_Status"};
	
		String pnm;
		String pds;
		String ps;
		DefaultTableModel model=new DefaultTableModel();
		model.setColumnIdentifiers(Colm);
		
		t=new JTable();
		t.setModel(model);
		t.setAutoResizeMode(JTable.AUTO_RESIZE_ALL_COLUMNS);
		t.setFillsViewportHeight(true);
		JScrollPane sp=new JScrollPane(t);
		sp.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
		sp.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
		
		try {
			Class.forName("org.postgresql.Driver");
			System.out.println("Driver loaded");
			
			Connection  conn = DriverManager.getConnection("jdbc:postgresql://192.168.100.10","tybcs3"," ");
			System.out.println("Connection established");
			Statement stmt = conn.createStatement();
			ResultSet rs =stmt.executeQuery("select * from Project");
			while(rs.next()) {
				id=rs.getInt(1);
				pnm=rs.getString(2);
				pds=rs.getString(3);
				ps=rs.getString(4);
				model.addRow(new Object[] {id,pnm,pds,ps});
			}
			f.add(sp);
			
			f.setSize(500,200);
			f.setVisible(true);
			conn.close();
		}
		catch(Exception e){
			System.out.println(e);
		}
	}
}
