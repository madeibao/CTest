
// 一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在第n次落地时，共经过多少米？第n次反弹多高？
#include<iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int n;// 代表的是n次落地。
    for(int i=1;i<=n;i++) {
        if(i==1) {
            sum+=high;
        }

        else{
            sum+=high*2;
        }
        high = high/2;
    }
    cout<<sum<< "  "<<high<<endl;



    return 0;//
}