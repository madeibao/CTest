

import java.util.*;

/**
 思路：最小几只大雁在叫
 1. 从头取开始遍历的完整的quack
 2. 遍历字符串统计所有的这个quack中有几个q（t）放在list中
 3. 在统计全部的字符串中判断能满足这t个q对应数量的quack最小值
 4. 取list中值跟小于t的最小值比较
 6. 返回t or n
 */
public class CountGeese {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String sound = sc.nextLine();
        Character[] soundType = {'q','u','a','c','k'};
        List<Character> record = new ArrayList<>(Arrays.asList(soundType));
        int value = count(sound,record);
        System.out.println(value);
    }
 
    //qququaauqccauqkkcauqqkcauqqkcaaukccakkkck  quackqquackuackqqqqquack
    public static int count(String sound, List<Character> record){
        List<Integer> qList = new ArrayList<>();
        int countq = 0;
        int index = 0;
        int len = record.size();
        //统计满足条件的q值数量
        for (int i = 0; i < sound.length(); i++){
            if (sound.charAt(i) == 'q'){
                countq++;
            }
            if (sound.charAt(i) == record.get(index)){
                if (index == len -1){
                    qList.add(countq);
                    countq = 0;
                    index = 0;
                    continue;
                }
                index++;
            }
        }
        if (qList.size() == 0){
            return -1;
        }
        //统计下所有q u a c k的值
        int q = 0;
        int u = 0;
        int a = 0;
        int c = 0;
        int k = 0;
        for (int i = 0; i < sound.length(); i++) {
            switch (sound.charAt(i)){
                case 'q':
                    q++;
                    break;
                case 'u':
                    u++;
                    break;
                case 'a':
                    a++;
                    break;
                case 'c':
                    c++;
                    break;
                case 'k':
                    k++;
                    break;
            }
        }
        //取 q u a c k最小值
        int min = Math.min(Math.min(Math.min(q, u), Math.min(a, c)), k);
        Collections.sort(qList,(m,n) -> n-m);
        for (int i = 0; i < qList.size(); i++){
            if (qList.get(i) <= min){
                return (qList.get(i));
            }
        }
        return min;
    }
 
}