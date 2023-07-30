#include<iostream>

using namespace std;

void Swap(char & a, char &b)
{ //将不是第一个元素的元素与第一个元素交互位置
	char t = a;
	a = b;
	b = t;
}

void Perm(char list[], char k, char m)//从第k位到第m位全排列
{
	if (k == m) //当k为最后一个元素时，不用交互了，直接输出。
	{
		for (char i = 0; i <= m; i++)
			cout << list[i];
		cout << endl;
	}

	//还有多个元素待排列，递归产生排列
	for (char i = k; i <= m; i++)
	{
		//第一个Swap函数中的 list[k] 一直是指向的待排列序列的第一个位置， list[i]则是待排列序列中的要与第一个位置的元素交互的元素
		Swap(list[k], list[i]); //交互位置
		Perm(list, k + 1, m);   // 当上一个Swap交互完成时，然后判断下一个元素
		Swap(list[k], list[i]); //当上面两个函数调用完成时，将数组还原成最初的形式
	}
}

int main()
{
	char list[] = {'a','b','c'};
	Perm(list, 0, 2); // 0,2表示0号元素到2号元素做全排列
	return 0;
}
