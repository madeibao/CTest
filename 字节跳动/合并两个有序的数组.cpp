

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i >= 0 && j >= 0) {
            if(A[i] < B[j]) { 
                A[k--] = B[j--];
            }
            else {
                A[k--] = A[i--];
            }
        }

        while(i >= 0) {
            A[k--] = A[i--];
        }

        while(j >= 0){
            A[k--] = B[j--];
        }
    }
};




int main(int argc, char* argv[]) {


	int num1[20] ={1,2,3,4,5,6};
	int m = 6;
	int num2[] ={2,3,4,6};
	int n = 4;

	Solution s;

	s.merge(num1, m, num2, n);
	for(int i:num1) {
		cout<<i<<" ";
	}
	return 0;
}
