


// 数组声明中，括号必须在变量名的后面。
// C++可以采用增强型的for 循环来实现数组的遍历。

#include<iostream>
using namespace std;

int main() {
      int num2[] = {1,2,3,4,5,6};
//    int length = sizeof(num2)/sizeof(int);
//    for(int i=0;i<length;i++) {
//        cout<<num2[i]<<endl;
//

    for(int j:num2) {
        cout<<j<<" "<<endl;
    }
    return 0;



}

//--——————————————————————————————————————————————————————————

#include<bits/stdc++.h>
using namespace std;

int main() {

    int nums[] = {2,34,42,2,34,4,5,23,};
    // 求数组的长度的方法为如下的两种
    int length = sizeof(nums)/sizeof(int)
    int length = sizeof(nums)/sizeof(nums[0]);
    for(int i=0;i<length;i++) {
        cout<<nums[i]<<" ";
    }


    return 0;
}

*/
