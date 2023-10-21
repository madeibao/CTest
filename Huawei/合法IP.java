

import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String str;
        while ((str = reader.readLine()) != null) {
            String[] s = str.split("\\.");
            boolean flag = true;
            if (s.length == 4) {

                for (String s1 : s) {
                    try {
                        int i = Integer.parseInt(s1);
                        if (i < 0 || i > 255) {
                            flag = false;
                        }
                    } catch (NumberFormatException err) {
                        flag = false;
                    }
                }
            } else {
                flag = false;
            }
            System.out.println(flag ? "YES" : "NO" );
        }
    }
}
