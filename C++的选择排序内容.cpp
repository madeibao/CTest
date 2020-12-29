
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class SelectionSort {
public:
    int* selectionSort(int* A, int n) {
        // write code here
        int k = 0;
        for (int i = 0; i < n-1; i++)
        {
            k = i;
            for (int j = i; j < n; j++)
            {
                if (A[k]>A[j])
                {
                    k = j;
                }
            }
            if (k!=i)
            {
                int temp = A[i];
                A[i] = A[k];
                A[k] = temp;
            }
        }
        return A;
    }
};


int main() {
    SelectionSort ss;
    int nums[]  = {2, 3, 3,5,5,3,23,29,20,13, 22,};
    int* num2;
    num2 = ss.selectionSort(nums, 11);
    for(int i=0;i<11;i++) {
        cout<<*num2<<" ";
        num2++;
    }
}
