
#include<iostream>
#include<bits/stdc++.h>

using namespace std; //

class Solution {
public:
    int findKth(vector<int> a, int n, int K) {
        return quickfind(a, 0, n-1, K);
    }
     
    int quickfind(vector<int>& a, int left, int right, int k) {
        int i = left;
        int j = right;
        int mark = a[left];
         
        while (i < j) {
            while (i < j && a[j] >= mark)
                --j;
            if (i < j)
                a[i++] = a[j];
             
            while (i < j && a[i] <= mark)
                ++i;
            if (i < j)
                a[j--] = a[i];
        }
        a[i] = mark;
         
        //哨兵右侧比他大的数字个数
        int big_num = right - i;
        
        //如果哨兵刚好是第K大的数
        if (k - big_num - 1 == 0)
            return mark;
        else if (k - big_num - 1 > 0) {
            //如果右侧数字个数不够K个，则从左侧找第k-big_num-1大的数
            return quickfind(a, left, i - 1, k - big_num - 1);
        } else {
            //如果右侧数字个数比K多，则在右侧找第K大的数
            return quickfind(a, i + 1, right, k);
        }
    }
};


int main(int argc, char *argv[]) {

    vector<int> res {1,2,3,4,5,6};
    int n=6;
    int k =3;
    Solution s;
    cout<<s.findKth(res, n, k);
    
    return 0;
}



