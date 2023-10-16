

import java.util.Arrays;
import java.util.Scanner;


public class MinNumTest {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            String[] arrays = in.nextLine().split(" ");

            System.out.println(minNum(arrays));
        }
    }

    public static minNum(String[] arrays) {
    	Arrays.sort(arrays,(o1,o2)->(o1+o2).compareTo(o2+o1));
    	boolean appendFirst = true;
    	StringBuilder sb = new StringBuilder();


    	// 首先遍历这些数字
    	for(String arr:arrays) {

    		if(arr.startsWith("0")) {
    			sb.append(arr);
    			continue;
    		}

    		if(appendFirst) {
    			sb.insert(0,arr);
    			appendFirst = true;
    			continue;

    		}

    		sb.append(arr);
    	}

		if (appendFirst) {
            return delZero(sb.toString());
        }
        return sb.toString();
    }

    /**
		删除字符串前面的0
    */
    public static String delZero(String str) {
    	int index = 0;
    	for(int i=0;i<str.length()-1;i++) {

    		if(str.charAt(i)!='0') {
    			break;
    		}
    		else {
    			index++;
    		}
		}
		return str.substring(index);
    }
}