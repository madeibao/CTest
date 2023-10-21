

/**
 * @Author 马远
 */

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String[] str = sc.nextLine().split(",");
            int target = Integer.parseInt(sc.nextLine());
            int res = -1;
            //转为数字数组
            if (str.length >= 3) {
                int[] arr = new int[str.length];
                for (int i = 0 ; i < arr.length ; i++) {
                    arr[i] = Integer.parseInt(str[i]);
                }


                //排序之后，进行三重循环比较
                Arrays.sort(arr);
                for (int i = 0 ; i < arr.length - 2 ; i++) {
                    for (int j = i + 1 ; j < arr.length - 1; j++) {
                        for (int k =  j + 1; k < arr.length ; k++) {
                            int a = arr[i];
                            int b = arr[j];
                            int c = arr[k];
                            if (a + b + c <= target) {
                                res = Math.max(res, a + b + c);
                            }
                        }
                    }
                }
            }
            System.out.println(res);
        }
    }
}
