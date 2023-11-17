


class Solution {
public:
    string convertToBase7(int num) {

        if(num==0) {
            return "0";
        }

        int flag = 1;
        if(num<0) {
            flag = -1;
            num = -num;
        }

        string str = "";
        while(num>0) {
            str.insert(0,to_string(num%7));
            num /= 7;
        }

        if(flag==-1) {
            str.insert(0,"-");
        }
        return str;

    }
};
