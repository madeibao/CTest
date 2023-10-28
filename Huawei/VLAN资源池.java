

import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String vlanResources = cin.nextLine();
        Integer vlanApply = cin.nextInt();
        cin.close();
        TreeSet<Integer> vSet = new TreeSet<>();
        String[] vlans = vlanResources.split(",");
        for (String vlan : vlans) {
            if (vlan.contains("-")) {
                String[] nums = vlan.split("-");
                int left = Integer.parseInt(nums[0]);
                int right = Integer.parseInt(nums[1]);
                for (int i = left; i <= right; i++) {
                    vSet.add(i);
                }
            } else {
                vSet.add(Integer.parseInt(vlan));
            }
        }

        // 移出已经申请的
        vSet.remove(vlanApply);
        ArrayList<Integer> list = new ArrayList<>(vSet);

        StringBuilder sb = new StringBuilder();

        Integer left = list.get(0);
        Integer right = left;
        for (int i = 1; i < list.size(); i++) {
            Integer value = list.get(i);
            if (value == right + 1) {
                right = value;
            } else {
                // 添加
                build(sb, left, right);
                left = right = value;
            }
        }
        build(sb, left, right);

        // 移除最后一个逗号
        System.out.println(sb.substring(0, sb.length() - 1));
    }

    private static void build(StringBuilder sb, Integer left, Integer right) {
        if (left.equals(right)) {
            sb.append(right).append(",");
        } else {
            sb.append(String.format("%s-%s,", left, right));
        }
    }
}
