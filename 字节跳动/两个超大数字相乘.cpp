



#include<iostream>
#include<string.h>
#include<cstring>
#include<cstdio>
#include<stdio.h>
#include<string>
using namespace std;
unsigned ione[200];
unsigned itwo[200];
unsigned result[400];
string slargeone;
string slargetwo;
//创建了两个字符串用来存储超大整数
int main(int argc,char *argv)
{
    int lengths1=0;
    int lengths2=0;
 
    cout<<"please input the first data"<<endl;
     cin>>slargeone;
    cout<<"please input the second data"<<endl;
    cin>>slargetwo;
    lengths1=slargeone.length();
    lengths2=slargetwo.length();
    memset(ione,0,sizeof(ione));
    memset(itwo,0,sizeof(itwo));
    memset(result,0,sizeof(result));
    //先初始化相关的数组保证数据的正确性
     int j=0;
     int i;
     //将字符串转化为整型数组
 	for(i=lengths1-1;i>=0;i--){
	 	ione[j++]=slargeone[i]-'0';
	}
	j=0;
	for(i=lengths2-1;i>=0;i--){
	 	itwo[j++]=slargetwo[i]-'0';
	}
	for(i=0;i<lengths1;i++){ //模拟乘法,将ione的每一位都与itwo的每一位相乘,然后结果存储于i+j
		for(j=0;j<lengths2;j++){
			result[i+j] += (ione[i] * itwo[j]);
		}
	}
    cout<<endl;
	//因为每一位做乘法会产生一位或者两位数,所以要将两位数的往前进一位
	for(i=0;i<400;i++){
		if(result[i] >= 10){
			result[i+1] += result[i] / 10;
			result[i] %= 10;
		}
	}
	bool ifiszone = false;
	for(i = 399;i>=0;i--){
		if(ifiszone){//如果第一位为零的话,那么就不输出相关的结果
			cout<<result[i];
		}else if(result[i]){//如果不为零的话,那么就输出结果
			cout<<result[i];
			ifiszone = true;
		}
	}
	//特殊情况的考虑,两个数的乘积为零
	if(!ifiszone){
		cout<<"0"<<endl;
	}
	return 0;
}




