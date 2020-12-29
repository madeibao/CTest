
/**

while (~scanf("%d%d",&n,&k)) {

}


从文件来读取其中的值 放在main函数的下面:
int main() {
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
    return 0;
}
#include<iostream>
#include<bits/stdc++.h>

ctrl+shift+c可以快速注释掉多行。
ctrl+shift+x可以取消注释，

    数组的大小的计算式，数组中的元素的个数。
    int ma[] = {2,23,4,3,4,5,5,};
    int len  = sizeof(ma)/sizeof(int);
    cout<<len<<endl;
    int len2 = sizeof(ma)/sizeof(ma[0]);
    cout<<len2<<endl;

*/

/**
#include<bits/stdc++.h>
using namespace std;

class CloseNumber {
public:
    vector<int> getCloseNumber(int x) {

        vector<int> res;
        if(x<=0) return res;

        int prev=x+1,next=x-1,num=getonenum(x);

        while(getonenum(next)!=num){
            --next;
        }
        res.push_back(next);
        while(getonenum(prev)!=num){
            ++prev;
        }
        res.push_back(prev);

        return res;
    }

private:
    int getonenum(int data){
        int n=0;
        while(data){
            ++n;
            data=data&(data-1);
        }
        return n;
    }
};

int main() {

    int x =8;
    vector<int> res;
    CloseNumber s;
    res= s.getCloseNumber(x);
    for(unsigned int i=0;i<res.size();i++) {
        cout<<res[i]<<" "<<endl;
    }
    return 0;
}

*/
