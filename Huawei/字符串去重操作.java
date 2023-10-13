
bach
bbaaccddfg


输出：
abc


import java.util.Scanner;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String target = sc.nextLine();
            String str = sc.nextLine();
            String[] any = target.split("");
            TreeSet<String> set2 = new TreeSet<String>();
            
            for(String s:any){
                if(str.contains(s)) {
                    set2.add(s);
                }
            }

            for(var s:set2){
                System.out.print(s);
            }
        }
    }
}