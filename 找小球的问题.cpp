#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {
	cout<<"9个球中找出质量较轻的一个"<<endl;
	cout<<"输入9个球的质量，要求是其中8个球的质量要相同，有任意一个球的质量偏重"<<endl<<endl;

	int nBall[8];

	for(int count=0;count<8;count++) {
		cout<<"请输入第"<<count+1<<"个球的质量:";
		cin>>nBall[count];
	}



	if(nBall[0]+nBall[1]+nBall[2]>nBall[3]+nBall[4]+nBall[5])
	{
		if(nBall[0]>nBall[1])
		{
			cout<<0+1<<endl;
		}
		else if(nBall[0]==nBall[1])
		{
			cout<<2+1<<endl;
		}
		else
		{
			cout<<1+1<<endl;
		}
	}
	else if(nBall[0]+nBall[1]+nBall[2]==nBall[3]+nBall[4]+nBall[5])
	{
		if(nBall[6]>nBall[7])
		{
			cout<<6+1<<endl;
		}
		else if(nBall[6]==nBall[7])
		{
			cout<<8+1<<endl;
		}
		else
		{
			cout<<7+1<<endl;
		}

	}
	else
	{
		if(nBall[3]>nBall[4])
		{
			cout<<3+1<<endl;
		}
		else if(nBall[3]==nBall[4])
		{
			cout<<5+1<<endl;
		}
		else
		{
			cout<<4+1<<endl;
		}

	}

	system("pause");

	return 0;
}
