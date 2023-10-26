

public class RepeatCode {
    public static void main(String[] args) {
        String value = "rghello123wohabc vfhello123ababc";
        String [] compare = value.split(" ");
        String a = compare[0];
        String b = compare[1];
       //双指针
        int left = 0;
        int right = 0;
        String end = null;
        StringBuffer sb = new StringBuffer();
        //以左指针为主，右指针为辅
        while (left != a.length() -1){
            if (a.charAt(left) == b.charAt(right)){
                sb.append(a.charAt(left));
                //双指针同时移动
                left++;
                right++;
            }else {
                //保存最长的重复序列
                if (end ==null || (end.length() < sb.length())){
                    end = sb.toString();
                }
                //初始化
                sb.setLength(0);
                right++;
            }
            //右指针走完一遍初始化
            if (right == b.length()-1 && left != a.length()-1){
                right = 0;
                left++;
            }
        }
        System.out.println(end);
    }
}