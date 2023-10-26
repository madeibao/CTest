
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * @Author 马远
 */
public class Main {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String value = sc.nextLine();
        StringBuffer sb = new StringBuffer();
        int index = 0;
        for (int i = 1; i <= value.length(); i++) {
            //1、去除字符串中非字母的符号
            Pattern pattern = Pattern.compile("[a-zA-Z]+");
            Matcher matcher = pattern.matcher((value.substring(index, i)));
            if (matcher.find()) {
                sb.append(matcher.group());
            }
            index++;
        }
        List<Info> end = save(sb);
        sort(end);
    }


    public static List<Info> save(StringBuffer sb) {
        //双指针
        int left = 0;
        int right = 1;
        int count = 0;
        Boolean flag = false;
        List<Info> infoList = new ArrayList<>();
        while (left != sb.length() && right != sb.length()) {
            //当前值
            String now = sb.substring(left, left + 1);
            //最后一个字符
            if (left + 1 == sb.length()) {
                Info info = new Info(0, now.toLowerCase(Locale.ROOT));
                infoList.add(info);
                break;
            }
            String after = sb.substring(right, right + 1);
            if (now.equalsIgnoreCase(after)) {
                count++;
                if (right - left <= 1) {
                    flag = true;//是否连续标志
                }
                if (right + 1 == sb.length()) {
                    if (flag) { //连续值+1
                        count++;
                    }
                    Info info = new Info(count, now.toLowerCase(Locale.ROOT));
                    infoList.add(info);
                    //移动右指针
                    right = left + 1;
                    left++; //移动左指针
                    count = 0;
                }
                right++;//连续值下标

            } else {
                // 2、如果出现连续字符 (不区分大小写) ，则输出: 该字符 (小) + 连续出现的次数
                if (flag) {//连续 中断时保存是数据
                    left = right;//跳过连续值
                    count++;
                    Info info = new Info(count, now.toLowerCase(Locale.ROOT));
                    infoList.add(info);
                    count = 0;
                    if (right + 1 == sb.length()) { //重新赋值右指针
                        right = left + 1;
                    }
                    // 3、如果是非连续的字符(不区分大小写) ，则输出: 该字符(小写) 该字母之后字符串中出现的该字符的次数
                } else if (!flag) { //非连续
                    if (right + 1 == sb.length()) {
                        Info info = new Info(count, now.toLowerCase(Locale.ROOT));
                        infoList.add(info);
                        count = 0;
                        right = left + 1;
                        left++;
                    }
                }
                right++;//跳过连续值
                if (right == sb.length()) {
                    right = left;
                }
                flag = false;
            }
        }
        return infoList;
    }

    /**
     * 4、对按照以上方式表示后的字符串进行排序: 字母和紧随的数字作为一组进行排序，数字大的在前，数字相同的则按字母进行排序，字母小的在前。
     *
     * @param infoList
     */
    public static void sort(List<Info> infoList) {
        Collections.sort(infoList, new SoutSummary());
        infoList.forEach(data -> System.out.print(data.getS() + data.getCount()));
    }

    static class SoutSummary implements Comparator<Info> {
        @Override
        public int compare(Info o1, Info o2) {
            //先比较次数的大小
            if (o1.getCount() > o2.getCount()) {
                return -1;
            } else if (o1.getCount() < o2.getCount()) {
                return 1;
                //如果次数相等
            } else {
                return o2.getS().compareTo(o2.getS());
            }
        }
    }


    static class Info {
        int count;
        String s;


        public Info(int count, String s) {
            this.count = count;
            this.s = s;
        }

        public Info() {
        }

        public int getCount() {
            return count;
        }

        public void setCount(int count) {
            this.count = count;
        }

        public String getS() {
            return s;
        }

        public void setS(String s) {
            this.s = s;
        }
    }
}
