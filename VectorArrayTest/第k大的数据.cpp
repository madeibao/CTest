

// 利用了快速排序的思想来实现数组中的第k大的数据。


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Finder {
public:
    void quicksort(vector<int>&a,int low,int high) {
        int pos;
        if(low<high) {
            pos = findpos(a,low,high);
            quicksort(a,low,pos-1);
            quicksort(a,pos+1,high);
        }
    }

    int findpos(vector<int>&a,int low,int high) {

    	// 首先是临时的变量值。
        int val=a[low];
        while(low<high) {
            while(low<high && a[high]>=val)
                high--;
            a[low] = a[high];
            
            while(low<high && a[low]<=val)
                low++;
            a[high] = a[low];
        }

        a[low]=val;
        return high;
    }

    int findKth(vector<int> a, int n, int K) {
        quicksort(a,0,n-1);
        return a[n-K];
        // write code here
    }
};


int main(int argc, char *argv[]) {

	vector<int> res {1,3,5,2,2,};
	int n = res.size();
	int k = 3;
	Finder ff;
	cout<<ff.findKth(res, n, k);
	return 0;
}