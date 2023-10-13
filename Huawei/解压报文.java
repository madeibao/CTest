

  public static void main(String[] args) {
        Stack<Integer> number = new Stack<>();
        Stack<String> str = new Stack<>();
        String value = "3[m2[c]]";
        int index1 = 0;
        StringBuffer sb = new StringBuffer();
        StringBuffer sbTemp1 = new StringBuffer();
        StringBuffer sbTemp2 = new StringBuffer();
 
        StringBuffer sbLoop = new StringBuffer();

        
        //方法1
        for (int i = 0 ;i < value.length(); i++){
            //入栈
            //方法1.通过正则表达式跟截取值分别入栈
            if (value.charAt(i) == '[' || value.charAt(i) == ']'){
                String temp = value.substring(index1,i);
                Pattern pattern = Pattern.compile("\\d+");
                Matcher matcher = pattern.matcher(temp);
                while (matcher.find()){
                    number.push(Integer.valueOf(matcher.group()));
                }
 
                Pattern pattern1 = Pattern.compile("[a-zA-Z]+");
                Matcher matcher1 = pattern1.matcher(temp);
                while (matcher1.find()){
                    str.push(String.valueOf(matcher1.group()));
                }
                index1 = i;
            }
 
            //出栈 "10[k]2[mn3[j2[op]]]"
            if (value.charAt(i) == ']') {
                //从数字栈跟字符串栈中推出值，进行拼接报文
                while (!str.empty() && !number.empty()) {
                    String temp = str.pop();
                    int size = number.pop();
                    sbTemp2.insert(0,temp);
                    for (int k = 0; k < size; k++) {
                       sbTemp1.append(sbTemp2);
                    }
                    sbTemp2 = sbTemp1;
                    sbTemp1 = new StringBuffer();
                }
            }
            sb = sb.append(sbTemp2);
            sbTemp1 = new StringBuffer();
            sbTemp2 = new StringBuffer();
        }


        System.out.println("sb:" + sb);
    }
}