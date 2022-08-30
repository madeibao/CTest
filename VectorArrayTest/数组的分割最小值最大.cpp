
题目复述：
对于一列有m个正整数元素的数组，用k-1个隔板把该数组分成连续的k份，每一份均非空。找出一种分法，使得这k份中每份求和的最小值达到最大。
且若多种情况同时达到最优，那么找出一种使得靠近左侧部分的和更大的情况。最后输出原数组加分隔符'/'的形式。
比如一个数组100 200 300 400 500 600 700 800 900，将其分为3份，
那么100 200 300 400 500 / 600 700 / 800 900 这种分法的最小和是600+700=1300，且不存在其他分法使其更大。
再比如1 1 1 1 1 1 1 1，k=3。有6种分法达到最优：
1 1 / 1 1 1 / 1 1 1
1 1 1 / 1 1 / 1 1 1
1 1 1 / 1 1 1 / 1 1
1 1 / 1 1 / 1 1 1 1
1 1 / 1 1 1 1 / 1 1
1 1 1 1 / 1 1 / 1 1


那么让左侧部分尽量大，就输出 1 1 1 1 / 1 1 / 1 1。（即第一部分尽量大，若第一部分相同，则第二部分尽量大，以此类推）
输入：第一行m,k，分别表示数组元素个数与分割的份数；第二行一组正整数，为待分割数组。
输出：一行分割后结果，在分割点用' / '标出，如上面例子输出 1 1 1 1 / 1 1 / 1 1。

/**
9 3
100 200 300 400 500 600 700 800 900
100 200 300 400 500 / 600 700 / 800 900
*
*/



#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int m, k, temp;
    cin >> m >> k;
    vector<int> nums;
    int sum_ = 0;

    // 对所有的结果值来进行处理。
    for (int i = 0; i < m; i++) {
        cin >> temp;
        sum_ += temp;
        nums.push_back(temp);
    }



    // 将加和平均化的方式来处理。
    int x = sum_ / k;

    for (int i = 0; i < k; i++) {
        int xx = 0;
        unsigned int j = 0;
        for(; j < nums.size(); j++) {
            xx += nums[j];
            if (xx - x > x - xx + nums[j]) {
                break;
            }
        }

        for (unsigned int m= 0; m < j; m++) {
        	// 输出各个元素之间含有空格的结果值。
            cout << nums[m] << " ";
        }

        if (i != k - 1) cout << "/ ";
        nums = vector<int> (nums.begin() + j, nums.end());
    }

    for (unsigned int ii = 0; ii < nums.size(); ii++) {
        cout << nums[ii] << " ";
    }
    return 0;
}
