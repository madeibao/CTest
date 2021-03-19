



#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void quick_sort(vector<int> &arr, int l, int r) {
        if (l < r) {
            int pivot = arr[l];
            int i = l;
            int j = r;
            while (i < j) {
                while (j > i && arr[j] > pivot) {
                    j--;
                }
                if (j > i) {
                    arr[i++] = arr[j];
                }
                while (i < j && arr[i] < pivot) {
                    i++;
                }
                if (i < j) {
                    arr[j--] = arr[i];
                }
            }
            arr[i] = pivot;
            quick_sort(arr, l, i - 1);
            quick_sort(arr, i + 1, r);
        }
    }
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    vector<int> MySort(vector<int>& arr) {
        // write code here
        quick_sort(arr, 0, arr.size() - 1);

        return arr;
    }
};

int main() {

    vector<int> res = {2,3,1,2,3,3,9,10,22,14,23};
    Solution s;
    vector<int> res2;
    res2 = s.MySort(res);
    for(int i:res2) {
        cout<<i<<" ";
    }

    return 0;
}
