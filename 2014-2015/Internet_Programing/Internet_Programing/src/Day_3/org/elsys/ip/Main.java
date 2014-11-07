package Day_3.org.elsys.ip;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Main {

	public static void main(String[] args) {
		if(args.length == 0){
			System.out.println("Not enough arguments");
			System.exit(0);
		}

		ArrayList<Person> list = new ArrayList<Person>();
		Person p1 = new Person("Pesho","Pesho","Ivanov");
		Person p2 = new Person("Ivanv","Pertov","Hristo");
		Person p3 = new Person("Georgi","M","C");
		Person p4 = new Person("Gergi","Perchu","Asd");
		Person p5 = new Person("Winny","The","Pooh");
		
		list.add(p1);
		list.add(p2);
		list.add(p3);
		list.add(p4);
		list.add(p5);
		
		Comparator<Person> comp = new Comparator<Person>() {
			@Override
			public int compare(Person p1, Person p2) {
				switch (args[0]) {
				case "1":
					return p1.getName().compareTo(p2.getName());

				case "2":
					return p1.getSurname().compareTo(p2.getSurname());
					
				case "3":
					return p1.getFamilyName().compareTo(p2.getFamilyName());
				}
				return 0;
			}
		};
		
		Collections.sort(list, comp);
		
		for(Person a : list){
			System.out.println(a.getName() + " " + a.getSurname() + " " + a.getFamilyName());
		}
		
	}
}
