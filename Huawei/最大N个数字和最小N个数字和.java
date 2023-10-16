
import java.util.*;

/**
 * @Author
 * @Date 2023/5/3 20:45
 * abababb
 */
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Integer> numList = new ArrayList<>();
        int count = Integer.parseInt(sc.nextLine());
        Arrays.stream(sc.nextLine().split(" ")).forEach(s -> {
            if (!numList.contains(Integer.parseInt(s))) {
                numList.add(Integer.parseInt(s));
            }
        });

        numList.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                if(o1>o2) {
                    return 1;
                }
                if(o1<o2) {
                    return -1;
                }
                return 0;
            }
        });

        // 最大和最小的 num 个数字
        int num = Integer.parseInt(sc.nextLine());
        List<Integer> num1 = new ArrayList<>();
        num1 = numList.subList(0, num);
        System.out.println(num1);

        // 判断两个集合之间是否有交集
        boolean flag = false;
        List<Integer> num2 = new ArrayList<>();

        // 截取其中的部分
        num2 = numList.subList(numList.size() - num, numList.size());
        System.out.println(num2);

        // 如果两个部分有交集
        for (int i = 0; i < num1.size(); i++) {
            if (num2.contains(num1.get(i))) {
                System.out.println("-1");
                flag = true;
                break;
            }
        }

        // 最大的 N 个数字和最小的 N 个数字来求和
        if (!flag) {
            int sum[] = new int[1];
            num1.stream().forEach(s -> {
                sum[0] += s;
            });
            num2.stream().forEach(s -> {
                sum[0] += s;
            });
            System.out.println(sum[0]);
        }
    }
}