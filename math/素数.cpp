


#include "iostream"
#include<bits/stdc++.h>

using namespace std;

    bool prime(int n) {
        for (int i = 2; i * i <= n; ++i)
            if (n % i == 0)
                return false;
        return n >= 2; // 1 不是质数
    }

int main() {

    cout<<prime(7)<<endl;
    return 0;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------

#include "iostream"
#include<bits/stdc++.h>

using namespace std;

    bool prime(int n) {
        for (int i = 2; i<int(sqrt(n)); ++i)
            if (n % i == 0)
                return false;
        return n >= 2; // 1 不是质数
    }

int main() {

    cout<<prime(7)<<endl;
    return 0;
}
