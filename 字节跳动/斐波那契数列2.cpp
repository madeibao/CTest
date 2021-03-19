


#include <iostream>
#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
	int getNth(int n) {
		if(n<=0) {return 0;}
		if(n==1) {return 1;}

		int pre = 0;
		int cur = 1;

		int i=2;
		while(i<=n) {

			int temp = cur+pre;
			pre= cur;
			cur= temp;
			i++;
		}
		return cur;
	}
};


// 递归实现

int main(int argc, char **argv) {

	int n = 4;
	Solution s;
	cout<<s.getNth(n)<<endl;
	return 0;
}
