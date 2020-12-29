
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int main() {

    // 数组来变成ector的形式来进行转化。
    float arrHeight[] = { 1.68,1.72,1.83,2.05,2.35,1.78,2.1,1.96 };
    vector<float> vecHeight(arrHeight, arrHeight+sizeof(arrHeight)/sizeof(float));
    for(int j=0;j<vecHeight.size();j++) {
        cout<<vecHeight.at(j)<<" ";
    }

    // vector来变成数组的形式进行转化

    return 0;
}



// 同理vector可以变成数组的形式。

#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

int main(int argc, char** argv) {

	vector<int> res ={1,2,3,4,5,6};
	int buffer[res.size()];
	copy(res.begin(), res.end(), buffer);


	// 指针来指向数组的第一个数字的首地址。
	int *p = &buffer[0];

	for(int i=0; i<res.size();i++) {	
		cout<<*(p+i)<<" ";
	}

	return 0;
}






















