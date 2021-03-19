

// 第n个丑数值。

#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int GetUglyNumber_Solution(int index) {

        queue<int> q_2,q_3,q_5;
        int res=0;    //index=0时，需要返回0

        //初始化，将 1 push 到3个对列里
        q_2.push(1);
        q_3.push(1);
        q_5.push(1);

        for(int i=0;i<index;i++)
        {
            //选取三个队列头部最小的值
            res = min(q_2.front(),min(q_3.front(),q_5.front()));

            //分别将res ×2, ×3, ×5 放到三个队列中
            q_2.push(res*2);
            q_3.push(res*3);
            q_5.push(res*5);

            //弹出三个队列的头部为res的数
            if(q_2.front()==res)
                q_2.pop();
            if(q_3.front()==res)
                q_3.pop();
            if(q_5.front()==res)
                q_5.pop();
        }

        // 返回结果值。
        return res;
    }
};


int main(int argc, char* argv[]) {

    Solution s;
    cout<<s.GetUglyNumber_Solution(3);
    return 0;
}


