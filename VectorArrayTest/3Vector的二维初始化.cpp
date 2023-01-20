
#include<iostream>
#include<vector>

using namespace std;

int main() {
    int r(2),c(4);
    vector<vector<int>> num(r, vector<int>(c));
    for(vector<int> i:num) {
        for(int j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<"------------------------"<<endl;

    // 初始化相关内容。
    vector<vector<int>> num2(r, vector<int>(c,1));
    for(vector<int> i:num2) {
        for(int j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}


////////////////////////////////////////////////////////////////
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {

    vector<vector<int> > va(2, vector<int>(4,1));//2行*4列,初始化为1

    vector<vector<int> > v(2);   //2行
    // v.resize(2);
    for(int i=0;i<v.size();i++){
        v[i].resize(4);          //4列
        for(int j=0;j<v[i].size();j++){
            v[i][j]=1;           //赋值
        }
    }

	return 0;
}


