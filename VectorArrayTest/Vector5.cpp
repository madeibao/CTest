

#include<bits/stdc++.h>
using namespace std;

int main(){
    // ��ͬ�ı������Ĳ�ͬ�Ľ��ֵ��
    vector<vector<int> > nums(8,vector<int>(13)); //��ά���������Ϊ8������Ϊ13��<int>��һ��Ҫ��һ���ո񣬷���ᱻ�б�Ϊ������>>����
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





