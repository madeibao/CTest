import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class T {
	static List<Integer> taskList = new ArrayList<Integer>();
	static int count = 0;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int gpu = Integer.parseInt(sc.nextLine());
		int taskNum = Integer.parseInt(sc.nextLine());
		String strTask = sc.nextLine();
		for (String item : strTask.split(" ")) {
			taskList.add(Integer.parseInt(item));
		}
		deal(gpu, 0);
		System.out.println(count);
	}

	public static void deal(int gpu, int toDeal) {
		if (taskList.size() == 0 && toDeal == 0) {
			return;
		}
		if (taskList.size() == 0) {
			count++;
			if (gpu < toDeal) {
				toDeal = toDeal - gpu;
				deal(gpu, toDeal);
			}
		} else if (toDeal > 0) {
			count++;
			toDeal = taskList.get(0) + toDeal - gpu;
			if (toDeal < 0) {
				toDeal = 0;
			}
			taskList.remove(0);
			deal(gpu, toDeal);
		} else if (toDeal == 0) {
			toDeal = taskList.get(0) - gpu < 0 ? 0 : taskList.get(0) - gpu;
			count++;
			taskList.remove(0);
			deal(gpu, toDeal);
		}
	}
}
