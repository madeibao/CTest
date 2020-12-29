#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int l,r;
    cin>>l>>r;
    int total = 0;
    for(int i = l; i <= r; i++) {
        int n=i;
        int sum = 0;
        int half = 0;
        vector<int> vec;
        while(n > 0) {
            vec.push_back(n % 10);
            sum += n % 10;
            n = n / 10;
        }
        if(sum % 2 == 0) {
            half = sum / 2;
            // 全都初始化位0的位置上。
            //之后这一小段用的是01背包，判断能装下最大的数和一半是否相等。
            // 后面来使用01背包的算法。
            vector<int> re(half+1);
            for(int i=0;i<vec.size();i++) {
                for(int j=half;j>=vec[i];j--) {
                    re[j]=max(re[j],re[j-vec[i]]+vec[i]);
                }
            }
            if(half==re[half]) {
              total++;
            }
        }
    }
    cout << total;
    return 0;
}
