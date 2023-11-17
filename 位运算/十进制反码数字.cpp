


class Solution {
public:
   int findComplement(int num) {
        //位运算
        unsigned int p = 1;
        while (p < num) {
            p <<= 1;
            p++;
        }
        return num^p;
    }
};