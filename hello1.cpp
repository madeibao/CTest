
#include<string.h>
#include<vector>
#include<iostream>
using namespace std;

int vecmain() {
    vector<int>obj;
    for(int i=0;i<10;i++) { //push_back(elem)����������������
        obj.push_back(i);
        cout<<obj[i]<<",";
    }
    obj.clear();  // �����������������
    for(int i=0;i<obj.size();i++) {
        cout<<obj[i]<<endl;
    }
    return 0;
}













