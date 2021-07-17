
#include<iostream>

using namespace std;
class Solution {
public:
    int numberOfDays(int Y, int M)
    {
        if(1==M || 3==M || 5==M || 7==M || 8==M || 10==M || 12==M)
        {
            return 31;
        }
        else if(4==M || 6==M || 9==M || 11==M)
        {
            return 30;
        }
        else
        {
            if(Y%100==0)
            {
                if(Y%400==0)
                {
                    return 29;
                }
                else
                {
                    return 28;
                }
            }
            else
            {
                if(Y%4==0)
                {
                    return 29;
                }
                else
                {
                    return 28;
                }
            }
        }
    }
};


int main() {
    int year = 1995;
    int month = 8;
    Solution s;
    cout<<s.numberOfDays(year, month)<<endl;

    return 0;
}





