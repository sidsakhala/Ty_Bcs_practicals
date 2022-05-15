import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class setC1 extends JFrame implements ActionListener 
{ 
 JTextField t1,t2,t3;
 JButton b1,b2,b3;
 JTextArea t;
 JPanel p1,p2;
 Hashtable ts;
 setC1()
 {
  ts=new Hashtable();
  t1=new JTextField(20);
  t2=new JTextField(10);
  t3=new JTextField(20);
  
  b1=new JButton("add");
  b2=new JButton("search");
  b3=new JButton("remove");
  
  t=new JTextArea(20,30);
  p1=new JPanel();
  p1.add(t);
  p2=new JPanel();
  p2.setLayout(new GridLayout(2,3));
  p2.add(t1);
  p2.add(t2);
  p2.add(b1);
  p2.add(t3);
  p2.add(b2);
  p2.add(b3);
  add(p1);
  add(p2);
  
  b1.addActionListener(this);
  b2.addActionListener(this);
  b3.addActionListener(this);
 
 setLayout(new FlowLayout());
 setSize(500,500);
 setVisible(true);
 setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 }
public void actionPerformed(ActionEvent e)
 {
 if(b1==e.getSource())
 {
  String name =t1.getText();
  int code = Integer.parseInt(t2.getText());
  ts.put(name,code);
  Enumeration k=ts.keys();
  Enumeration v=ts.elements();
  String msg=" ";
while(k.hasMoreElements())
 {
  msg=msg+k.nextElement()+"="+v.nextElement()+"\n";
 }
  t.setText(msg);
  t1.setText("");
  t2.setText("");
 }
else if(b2==e.getSource())
   {
    String name =t3.getText();
    if(ts.containsKey(name))
    {
     t.setText(ts.get(name).toString());
    }
    else
    JOptionPane.showMessageDialog(null,"city not found ");
   }

else if(b3==e.getSource())
{ 
   String name=t3.getText();
  if(ts.containsKey(name))
  {
   ts.remove(name);
   JOptionPane.showMessageDialog(null,"city deleted");
  }
 else
 JOptionPane.showMessageDialog(null,"city not present");
}

 }
public static void main(String args[])
  {
   new setC1();
  }
}




 


