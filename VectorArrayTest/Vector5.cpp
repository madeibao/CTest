

#include<bits/stdc++.h>
using namespace std;

int main(){
    // 不同的编译器的不同的结果值。
    vector<vector<int> > nums(8,vector<int>(13)); //二维数组的行数为8，列数为13。<int>后一定要加一个空格，否则会被判别为操作符>>出错
    int b[8][13] = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                    {0,0,0,0,0,0,0,1,1,1,0,0,0},
                    {0,1,1,0,1,0,0,0,0,0,0,0,0},
                    {0,1,0,0,1,1,0,0,1,0,1,0,0},
                    {0,1,0,0,1,1,0,0,1,1,1,0,0},
                    {0,0,0,0,0,0,0,0,0,0,1,0,0},
                    {0,0,0,0,0,0,0,1,1,1,0,0,0},
                    {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 13; j++){
            nums[i][j] = b[i][j];
        }
    }
    for(unsigned int i=0;i<nums.size();i++) {
        for(unsigned int j=0;j<nums[0].size();j++) {
            cout<<nums[i][j]<< " ";
        }
        cout<<endl;
    }
    return 0;
}






