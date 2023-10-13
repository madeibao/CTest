

import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * @ClassName Main
 * @Author：Mayuan
 * @Date 2021/4/11/0011 20:56
 * @Description TODO
 * @Version 1.0
 * <p>
 * 在一些考试中，类的命名常常为 Main
 **/


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[]services = sc.nextLine().split(",");
        String[]error = sc.nextLine().split(",");
        //用Map来存储依赖关系
        Map<String,String> ser = new LinkedHashMap<>();
        for (int i = 0; i < services.length; i++){
            String[]equ = services[i].split("-");
            ser.put(equ[0], equ[1]);
        }
        check(ser,error);
    }
    
    public static void check(Map<String,String> ser,String[] error){
        for (int i = 0; i < error.length; i++){
            String errorequ = error[i];
            //移除坏的设备
            Iterator<Map.Entry<String,String>> it = ser.entrySet().iterator();
            while (it.hasNext()){
                Map.Entry<String,String> entry = it.next();
                if (entry.getValue().equals(errorequ)){
                    it.remove();
                }
            }
            //保证不了按输入顺序排序
           /* ser = ser.entrySet().stream()
                    .filter(entry -> !entry.getValue().equals(errorequ))
                    .collect(Collectors.toMap(Map.Entry::getKey,Map.Entry::getValue));*/

        }//a1-a2,a5-a6,a2-a3  a5,a2
        //输出正常的服务器号


        if (ser.size() == 0) {
            System.out.println(",");
        }else {
            Iterator<Map.Entry<String,String>> it = ser.entrySet().iterator();
            while (it.hasNext()){
                Map.Entry<String,String> entry = it.next();
                System.out.print(entry.getValue());
                if (!it.hasNext()){
                    break;
                }
                System.out.print(",");
            }
        }
    }
}