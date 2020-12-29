
#include<iostream>
#include<string>
#include<algorithm>

#include<bits/stdc++.h>


using namespace std;
int main()
{
    string stra;
    string strb;
    while(cin >> stra >> strb)
    {
        bool flag = false;
        for(int i = 0; i < stra.size(); i++)
        {
            if(!(stra[i] >= '0' && stra[i] <= '9'))
            {
                cout << "error" << endl;
                flag = true;
                break;
            }
                 
        }
        if(flag)
            break;
        for(int i = 0; i < strb.size(); i++)
        {
            if(!(strb[i] >= '0' && strb[i] <= '9'))
            {
                cout << "error" << endl;
                flag = true;
                break;
            }
                 
        }
        if(flag)
            break;
         
        string ret;
        int carry = 0;
        int i = stra.size() - 1;
        int j = strb.size() - 1;
        while(i >= 0 && j >= 0)
        {
            int sum = (stra[i] - '0') + (strb[j] - '0') + carry;
            carry = sum / 10;//计算carry和sum不能调换顺序
            sum = sum % 10;
            ret = ret + to_string(sum);
            i--;
            j--;
        }
        while(i >= 0)
        {
            int sum = (stra[i] - '0') + carry;
            carry = sum / 10;
            sum = sum % 10;
            ret = ret + to_string(sum);
            i--;
        }
        while(j >= 0)
        {
            int sum = (strb[j] - '0') + carry;
            carry = sum / 10;
            sum = sum % 10;
            ret = ret + to_string(sum);
            j--;
        }
        if(carry)
            ret = ret + '1';
        reverse(ret.begin(), ret.end());
        cout << ret << endl;
         
    }
}