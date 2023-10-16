


import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

public class T43 {
	public static void main(String[] args) {
		String input = "a:3,b:5,c:2,d:10@a:1,b:2,d:3";
		String allKeyValue[] = input.split("@")[0].split(",");
		String usedKeyValue[] = input.split("@")[1].split(",");
		Map<String, Integer> map = new HashMap<String, Integer>();
		String lastKey = "";
		for (String keyValue : allKeyValue) {
			String key = keyValue.split(":")[0];
			int value = Integer.parseInt(keyValue.split(":")[1]);
			map.put(key, value);
			lastKey = key;
		}
		for (String keyValue : usedKeyValue) {
			String key = keyValue.split(":")[0];
			int value = Integer.parseInt(keyValue.split(":")[1]);
			map.put(key, map.get(key) - value);
		}
		for (Entry<String, Integer> entry : map.entrySet()) {
			System.out.print(entry.getKey() + ":" + entry.getValue());
			if (!entry.getKey().equals(lastKey)) {
				System.out.print(",");
			}
		}
	}
}

