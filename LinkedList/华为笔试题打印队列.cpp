//02 打印机任务
#define _CRT_SECURE_NO_WARNINGS
/*
打印机任务
简要描述：
某个打印机根据打印机队列执行打印任务，打印任务分为九个优先级，分别用数字1~9表示，数字越大优先级越高。
打印机每次从队列头部取出第一个任务A，然后检查队列余下任务中有没有比A优先级更高的任务，则将任务A放在队列尾部，
否则就执行任务A的打印。请编写一个程序，根据输入的打印队列，编出实际的打印顺序。
输入描述：
函数原型： void printOrder(const int input[], int len, int output[])
输入参数input表示打印队列，为一个由整数1~9（优先级）组成的数组，数组索引0表示打印队列头部。
对于C/C++,参数len表示input数组的长度。可以假定输入的参数总是合法有效的，input数组长度有可能为0，但不会是空指针。
输出为一个表示实际打印顺序的数组，其数组项为打印任务在输入数组中的索引值（从0开始）。
Java通过返回值输出。C/C++通过输出参数output[]输出，可以假定为存放结果分配了足够的空间
。。。。题目其余部分没有记录，有人记录的，可以希望在留言处补全，大家一起分享交流。
输入样例：
9, 3, 5
输出样例：
0, 2, 1
*/
 
 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
 
#define MAX 500
 
int input[MAX];
 
//循环队列的结点数据元素
struct QNode
{
	int num;
	int idx;
};
 
typedef struct Que
{
	QNode* elem;
	int front;
	int rear;
	int len;
	int sz;
}CyQueue;
 
void initQueue(CyQueue& Q)
{
	Q.front = Q.rear = 0;
	Q.len = Q.sz = 0;
	Q.elem = nullptr;
}
 
bool isEmpty(CyQueue Q)
{
	return Q.len == 0;
}
 
int nextIdx(CyQueue Q, int cur)
{
	return (cur + 1) % (Q.sz + 1);
}
 
//Q 非空
//返回循环队列的最大优先级的索引号
int getMax(CyQueue Q)
{
	int maxNum = Q.front;
	int i = nextIdx(Q, Q.front);
	for(; i != Q.rear; i = nextIdx(Q, i))
	{
		if(Q.elem[i].num > Q.elem[maxNum].num)
		{
			maxNum = i;
		}
	}
	return maxNum;
}
 
//删除节点
void Pop(CyQueue& Q)
{
	Q.front = nextIdx(Q, Q.front);
	--Q.len;
}
 
//获得队头元素
QNode getFront(CyQueue& Q)
{
	return Q.elem[Q.front];
}
 
//插入节点
void Push(CyQueue& Q, QNode& q)
{
	Q.elem[Q.rear] = q;
	Q.rear = nextIdx(Q, Q.rear);
	++Q.len;
}
 
//主函数  打印序列
void printOrder(const int input[], int len, int output[])
{
	CyQueue Q;
	initQueue(Q);
	Q.len = len;
	Q.sz = len + 1;
	Q.elem = new QNode[len + 1];
	for(int i = 0; i < len; ++i)
	{
		Q.elem[i].num = input[i];
		Q.elem[i].idx = i;
	}
	Q.front = 0;
	Q.rear = len;
	int numOut = 0;
	while(!isEmpty(Q))
	{
		int pos = getMax(Q);
		for(int i = Q.front; i != pos; i = nextIdx(Q, i))
		{
			QNode q = getFront(Q);
			Pop(Q);
			Push(Q, q);
		}
		QNode q = getFront(Q);
		output[numOut++] = q.idx;
		Pop(Q);
	}
}
 
int main()
{
#if 1
	freopen("in01.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int len = 0;
	int num;
	char c;
	while(cin >> num)
	{
		//处理逗号的输入
		cin >> c;
		input[len++] = num;
	}
	int output[MAX] = {0};
	printOrder(input, len, output);
 
	for(int i = 0; i < len; ++i)
	{
		if(i != len - 1)
		{
			cout << output[i] << ", ";
		}
		else
		{
			cout << output[i];
		}
	}
	return 0;
}