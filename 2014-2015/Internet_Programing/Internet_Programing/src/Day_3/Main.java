package Day_3;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Main {
	public static <T> void main(String[] args) {
		ArrayList<String> list = new ArrayList<String>();
		list.add("xcvsdwas");
		list.add("sdqwewssdasd");
		list.add("asdasdw");
		list.add("opjsdw");
		list.add("mnbhasdwd");
		
		//list.sort(null);

		Comparator c = new Comparator() {
			public int compare(String arg0, String arg1) {
				return arg0.length() - arg1.length();
			}

			@Override
			public int compare(Object arg0, Object arg1) {
				// TODO Auto-generated method stub
				return 0;
			}
		};
		
		Collections.sort(list, c);
		
		for(int i = 0; i < list.size(); i++){
			System.out.println(list.get(i));
		}

	}
}





/*
 Ako iskam da dobavqme i mahame chesto elementi polzvame Linked List
 get() pri LinkedList e skupa operaciq(obhojda celiq List)
 
 
 */