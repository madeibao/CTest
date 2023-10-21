


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int[] arr = new int[num];
        for (int i = 0; i < num; i++) {
            arr[i] = sc.nextInt();
        }
        List<Integer> list = new ArrayList<>();
        int[] co = Arrays.copyOf(arr, num);
        for (int i = 0 ; i < arr.length ; i++) {
            for (int j = i + 1 ; j < co.length ; j++) {
                if (arr[i] < co[j]) {
                    list.add(j);
                    break;
                } else if (j == co.length - 1) {
                    list.add(0);
                }
            }
        }
        list.add(0);
        for (int i : list) {
            System.out.print(i + " ");
        }
    }
}
