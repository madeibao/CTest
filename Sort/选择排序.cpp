

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

void select_sort(int a[], int n) {
    int i;        // 有序区的末尾位置
    int j;        // 无序区的起始位置
    int min;    // 无序区中最小元素位置

    for(i=0; i<n; i++) {
        min=i;

        //找"a[i+1]..a[n]"之间最小元素，并赋给min
        for(j=i+1; j<n; j++) {
            if(a[j] < a[min])
                min=j;
        }

        //若min!=i，则交换 a[i] 和 a[min]。
        //交换后，保证了a[0]..a[i]之间元素有序。
        if(min != i)
            swap(a[i], a[min]);
    }
}

int main(int argc, char** argv) {

	int nums[]= {2,3,1};
	select_sort(nums, 3);
	for(int i:nums) {
		cout<<i<<" ";
	}
	return 0;
}
