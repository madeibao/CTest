
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


//----------------------------------------------------------------------------

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    vector<vector<int>> nums = {{1,1,3},
                                {2,3,4},
                                {9,9,8}};


    int m = nums.size();
    int n = nums[0].size();

    // 按照每一行来进行统计
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }

    // 按照列来进行打印
    cout<<"----------------------------"<<endl;
    // 按照每一列来进行统计
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<nums[j][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

