


// 配对交换。编写程序，交换某个整数的奇数位和偶数位，尽量使用较少的指令（也就是说，位0与位1交换，位2与位3交换，以此类推）。

// 示例1:

//  输入：num = 2（或者0b10）
//  输出 1 (或者 0b01)
// 示例2:

//  输入：num = 3
//  输出：3


// 分别取出数字二进制奇数位和偶数位
// 将奇数位的二进制放在偶数位（即右移
// 将偶数位的二进制放在奇数位（即左移

// 0xaaaaaaaa
// 0x10101010101010101010101010101010


// 0x55555555
// 0x01010101010101010101010101010101


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int exchangeBits(int num) {
        int even = (num & 0xaaaaaaaa) >> 1;  // 奇数右移
        int odd =  (num & 0x55555555) << 1;  // 偶数位置左移
        return even | odd;
    }
};

int main() {

    int n = 2;
    Solution s2;
    cout<<s2.exchangeBits(n)<<endl;
    return 0;
}
