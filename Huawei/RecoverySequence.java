
import java.util.List;
import java.util.ArrayList;
import java.util.*;
import java.util.Scanner;

public class RecoverySequence {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long num = sc.nextLong();
        long len = sc.nextInt();
        long min = minNum(num,len);
        System.out.println(min);
    }
    public static long minNum(long num, long len){
        List<Long> nums = new ArrayList<>();
        List<Long> begin = new ArrayList<>();
        while (num > 0){
            long digit = num % 10;
            nums.add(digit);
            begin.add(digit);
            num = num / 10;
        }
        //序列值范围 19801211 5 -->8    1611231145 5 -->12    8088456888789199 8 -->84 111002011304101065 6 -->101
        long minRange = nums.size()/len;
        long maxRange = (long) Math.ceil(Double.valueOf(nums.size())/len);
        //boolean区分起始值跟终值
        minRange = range(minRange,true);
        maxRange = range(maxRange,false);
        int count = 0;
        Boolean con = true;
        List<Long> value = new ArrayList<>();
        for (long i = minRange; i < maxRange; i++){
            long t = i;
            while (t > 0){
                //将整数值一个个拆分出来
                Long digit = t % 10;
                value.add(digit);
                t = t / 10;
            }
            //分拆
            for (int j = 0; j < value.size(); j++){
                //满足则删除，计数+1，且list列表长度为0
                if (nums.contains(value.get(j))){
                    nums.remove(value.get(j));
                }else {
                    //初始化恢复
                    con = false;
                    nums = new ArrayList<>(begin);
                    //恢复到开始连续的伪序列号位置
                    i = i - count;
                    count = 0;
                    break;
                }
            }
            if (con){
                count++;
            }else if (!con){
                con = true;
            }
            value = new ArrayList<>();
            //满足连续的正整数序列
            if (count == len && nums.size() == 0){
                return (i-count + 1);
            }
        }
        return count;
    }
 
    /**
     * 定义循环的区间范围（位数）
     * @param value
     * @param b
     * @return
     */
    public static long range(long value ,Boolean b){
        if (b){
            value =  (long) Math.pow(10,value -1);
        }else {
            value =  (long) Math.pow(10,value);
        }
        return value;
    }
 
}