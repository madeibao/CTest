



#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<int> nums {1,2,3,4,5,6,2};
    int t = 0;
    int temp(0);
    while(temp<7) {
        cout<<nums[t]<<" ";
        t = nums[t];
        temp++;

    }
    return 0;
}



// 两倍的方式来进行工程掘进。


#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<int> nums {1,2,3,4,5,6,7,8,9};
    int t = 0;
    int temp(0);
    while(temp<7) {
        cout<<nums[t]<<" ";
        t = nums[nums[t]];
        temp++;

    }
    return 0;
}
