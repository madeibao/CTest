

/**

3、Sort函数有三个参数：（第三个参数可不写）

（1）第一个是要排序的数组的起始地址。
（2）第二个是结束的地址（最后一位要排序的地址）
（3）第三个参数是排序的方法，可以是从大到小也可是从小到大，还可以不写第三个参数，此时默认的排序方法是从小到大排序。
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int a[] ={1,2,1,3,4,5,6,5};
    sort(a,a+8);
    for(int i:a) {
        cout<<i<<" "<<endl;
    }
    return 0;
}
*/


