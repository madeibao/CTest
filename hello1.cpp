
#include<string.h>
#include<vector>
#include<iostream>
using namespace std;

int vecmain() {
    vector<int>obj;
    for(int i=0;i<10;i++) { //push_back(elem)在数组最后添加数据
        obj.push_back(i);
        cout<<obj[i]<<",";
    }
    obj.clear();  // 清除容器中所以数据
    for(int i=0;i<obj.size();i++) {
        cout<<obj[i]<<endl;
    }
    return 0;
}
















