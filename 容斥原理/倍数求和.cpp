

LeetCode 2652. 倍数求和：O(1)做法 - 容斥原理

输入：n = 7
输出：21
解释：在 

 [1, 7]

范围内能被 3、5、7 整除的所有整数分别是
 3、5、6、7

数字之和为 
21


class Solution {
private:
    int n;
    inline int f(int k) {
        return (k + n / k * k) * (n / k) / 2;  // (首项 + 尾项) * 项数 / 2
    }

public:
    int sumOfMultiples(int n) {
        this->n = n;
        return f(3) + f(5) + f(7) - f(15) - f(21) - f(35) + f(105);
    }
};
