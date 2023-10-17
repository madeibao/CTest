

/**
 * 
 * 
 * 
 * 
180 70
198 60
175 80
175 70
175 60
198 90
199 100
170 55
170 60
170 65
177 88
185 80
//拔河比赛


 */

import java.util.ArrayList;
import java.util.Scanner;

public class T69 {
	static class Person {
		int w;
		int h;

		public Person(int w, int h) {
			this.w = w;
			this.h = h;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ArrayList<Person> persons = new ArrayList<>();
		while (sc.hasNextLine()) {
			String line = sc.nextLine();
			if (line.equals(""))
				break;
			Person person = new Person(Integer.parseInt(line.split(" ")[1]), Integer.parseInt(line.split(" ")[0]));
			persons.add(person);
		}
		persons.sort((p1, p2) -> p1.h != p2.h ? p2.h - p1.h : p2.w - p1.w);
		for (int i = 0; i < 10; i++) {
			System.out.println(persons.get(i).h + " " + persons.get(i).w);
		}
	}
}

