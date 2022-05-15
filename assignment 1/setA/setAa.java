import java.util.*;

class setAa{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("how many cities you want to enter");
		int n = sc.nextInt();
		ArrayList<String> al = new ArrayList<>();
		for(int i=0; i<n; i++){
			System.out.println("Enter the name of "+(i+1)+ " city");
			String c = new String(sc.next());
			al.add(c);
		} 
		System.out.println("The cities inserted in ArrayList are :");
		System.out.println(al);
		al.clear();
		System.out.println("The arrayList after removing the elements is");
		System.out.println(al);
	}	
}
