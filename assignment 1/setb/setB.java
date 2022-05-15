import java.util.*;
class setB{
	public static void main(String[] args 	){
		HashMap hm = new HashMap();
		hm.put("bj",new Double(9));
		hm.put("aj",new Double(9.7));
		hm.put("ap",new Double(9.8));
		hm.put("am",new Double(9.6));
		System.out.println("Elements before sorting");
		System.out.println(hm);
		TreeMap tr = new TreeMap(hm);
		hm.clear();
		System.out.println("Elements after sorting");
		System.out.println(tr);
	}
}
