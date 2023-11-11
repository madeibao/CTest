
#include <iostream>
#include <algorithm>
using namespace std;


int main(void){
    int a[8] = {2, 2, 2, 4, 4, 6, 7, 8};
    int c;
    sort(a, a + 8);  //对于无序的数组需要先排序
    c = (std::unique(a, a + 8) - a );
    cout<< "c = " << c << endl;
    //打印去重后的数组成员
    for (int i = 0; i < c; i++)
        cout<< "a = [" << i << "] = " << a[i] << endl;
    return 0;
}


//unique()函数并非真正去重，而是将重复的元素放到容器的末尾或者数组的末尾，
//比如1,4,4,6,6这个序列，在使用unique()函数后得到的新序列是1,4,6,4,6，函数的返回值是第二个4的地址。
//


#include <iostream>
#include <algorithm>
using namespace std;


int main(void){
    int a[8] = {2, 2, 2, 4, 4, 6, 7, 8};
    sort(a, a + 8);  //对于无序的数组需要先排序
    unique(a,a+8);

    for(auto i:a) {
        cout<<i<<" ";
    }
    return 0;
}
