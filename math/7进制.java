


class Solution {
    public String convertToBase7(int num) {
        return Integer.toString(num,7);
    }
}

class Solution {
    public String convertToBase7(int num) {

        if(num==0) {
            return "0";
        }

        boolean flag = false;

        if(num<0) {
            flag = true;
            num = num*(-1);
        }

        StringBuilder sb = new StringBuilder();

        while(num!=0) {
            sb.append(num%7);
            num = num/7;
        }

        if(flag) {
            sb.append('-');
        }

        sb.reverse();

        return sb.toString();
    }

}

//-----------------------------------------------------------------------------


class Solution {
    public String convertToBase7(int num) {

        if(num==0) {
            return "0";
        }

        boolean flag = false;

        if(num<0) {
            flag = true;
            num = num*(-1);
        }
        StringBuilder sb = new StringBuilder();

        while(num!=0) {
            sb.insert(0, String.valueOf(num%7));
            num = num/7;
        }

        if(flag) {
            sb.insert(0,'-');
        }

        return sb.toString();
    }

}