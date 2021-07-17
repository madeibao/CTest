
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
    int getonenum(int data) {
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




