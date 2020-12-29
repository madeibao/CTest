

// 并查集合求旅行的次数，
// 算法的思想就是并查集。
// 输入和输出的具体的形式待查找。
/*

3 
a a
b c
c d

*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int count;
    cin>>count;
    vector<pair<string,string>>res;
    string str1,str2;
    for(int i = 0;i < count;i++) {
        cin>>str1>>str2;
        res.push_back({str1,str2});
    }
    int len = 1;

    // 保存的列表的大小。
    count = res.size();
    for(int i = 0;i < count - 1;i++){
        if(res[i].second != res[i + 1].first)len++;
    }
    cout<<len<<endl;
    return 0;
}
