

#include <iostream>
using namespace std ;

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;
int nus(vector<int> a) {
    sort(a.begin(),a.end());
    int l=a[a.size()-1]; //left
    int r=l;             // right
    int i=0,j=a.size()-2;
    long long int sum=0;
    while(i<j){
            int li=abs(l-a[i]),ri=abs(r-a[i]);
            int lj=abs(l-a[j]),rj=abs(r-a[j]);
            if(li>ri||lj>rj){ //left side
                    if(li>lj){
                            sum+=li;
                            l=a[i++];
                    }else{
                            sum+=lj;
                            l=a[j--];
                    }
            }else{
                    if(ri>rj){
                            sum+=ri;
                            r=a[i++];
                    }else{
                            sum+=rj;
                            r=a[j--];
                    }
            }
            //cout<<l<<"---"<<r<<"------"<<i<<"---"<<j<<"----------"<<sum<<endl;
    }
    sum+=max(abs(l-a[i]),abs(r-a[i]));
    return sum;

}
int main() {
    int n;
    cin >> n;
    vector<int> res(n, 0);
    for (auto &m : res)
        cin >> m;

    cout<<nus(res)<<endl;
    return 0;
}


