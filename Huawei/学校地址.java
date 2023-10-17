

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;


public class SchoolAddress {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Integer> address = Arrays.stream(sc.nextLine().split(" "))
                .map(Integer::parseInt).collect(Collectors.toList());
        int endAdress = minAdress(address);
        System.out.println(endAdress);
 
    }
 
    public static int minAdress(List<Integer> address){
        Collections.sort(address);
        //判断奇偶性
        Boolean x = address.size() % 2 == 0 ? true:false;
        int min;
        if (x) {
            min = address.get(address.size()/2 - 1);
        }
        else {
            min = address.get(address.size()/2);
        }
        return min;
    }
}