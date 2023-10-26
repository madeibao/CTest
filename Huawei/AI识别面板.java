

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class T70 {
	static class Light {
		int id, x1, y1, x2, y2;

		public Light(int id, int x1, int y1, int x2, int y2) {
			super();
			this.id = id;
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
		}
	}

	static List<Light> lightList = new ArrayList<>();

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = Integer.parseInt(sc.nextLine());
		for (int i = 0; i < num; i++) {
			String line = sc.nextLine();
			String numStrArr[] = line.split(" ");
			int id = Integer.parseInt(numStrArr[0]);
			int x1 = Integer.parseInt(numStrArr[1]);
			int y1 = Integer.parseInt(numStrArr[2]);
			int x2 = Integer.parseInt(numStrArr[3]);
			int y2 = Integer.parseInt(numStrArr[4]);
			Light light = new Light(id, x1, y1, x2, y2);
			lightList.add(light);
		}
		while (lightList.size() > 0) {
			Light maxLight = getMaxLight();
			System.out.print(maxLight.id + " ");
			List<Light> sameLineLights = getSameLineLights(maxLight);
			sameLineLights.sort(new Comparator<Light>() {
				@Override
				public int compare(Light l1, Light l2) {
					if (l1.x1 < l2.x1)
						return -1;
					if (l1.x1 > l2.x1)
						return 1;
					return 0;
				}
			});
			for (Light l : sameLineLights) {
				System.out.print(l.id + " ");
			}
		}
	}

	// 找出未排序的最大的那个
	public static Light getMaxLight() {
		Light light = null;
		for (Light lt : lightList) {
			if (light == null) {
				light = lt;
			}
			if (lt.y1 < light.y1) {
				light = lt;
			}
			if (lt.y1 == light.y1) {
				// 高度一样 那么以左侧为主
				if (lt.x1 < light.x1) {
					light = lt;
				}
			}
		}
		lightList.remove(light);
		return light;
	}

	// 找出和最大的灯处于同一行的
	public static List<Light> getSameLineLights(Light light) {
		List<Light> lights = new ArrayList<>();
		for (Light lt : lightList) {
			if (lt.y1 == light.y1 || (light.y1 - lt.y1) >= (light.y1 - light.y2) / 2) {
				lights.add(lt);
			}
		}
		lightList.removeAll(lights);
		return lights;
	}
}

