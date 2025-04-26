
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void panCakeSort(vector<int>& v, int k);
int getIndex(vector<int>&v, int k);
void swap(vector<int>&v, int k);

void panCakeSort(vector<int>& v) {
    int n = v.size();
    for(int i=n;i>1;i--) {
        int index = getIndex(v, i);
        if(index != i-1) {
            swap(v, index);
            swap(v, i-1);
        }
    }
}

int getIndex(vector<int> &v, int k) {
    int index = 0;
    for(int i=0;i<k;i++) {
        if(v[i] >= v[index]) {
            index = i;
        }
    }
    return index;
}

void swap(vector<int> &v, int k) {
    int i = 0, j = k;
    while(i < j) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }
}

int main() {
    vector<int> v = {1, 2, 3,3,2,1, 4, 5};
    panCakeSort(v);
    for(unsigned int i=0;i<v.size();i++) {
        cout<<v[i]<<" ";
    }
    return 0;
}
