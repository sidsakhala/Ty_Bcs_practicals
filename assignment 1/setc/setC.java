import java.util.*;


class setC{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);		
		int n = 0;
		TreeMap tr = new TreeMap();
				
		do{		
			System.out.println("Select the operation you want to perform\n 1. Add new city and its code \n 2.Remove a city from the collection\n  3.Search for city name and display the code\n 4.Exit");
		n = sc.nextInt();
		
	
		
		switch(n){
			case 1 : System.out.println("Enter name of the city");
				System.out.println("Enter the STD code");
				tr.put(new String(sc.next()), new Integer(sc.nextInt()));
				break;
			case 2 : System.out.println("Enter the name of city");
				tr.remove(new String(sc.next()));
				break;
			case 3 :System.out.println("Enter the name of city");
				System.out.println("The code is "+ tr.get(new String(sc.next())));
				break;
			case 4 :break; 
		}
		}while(n!=4);
	}
}
