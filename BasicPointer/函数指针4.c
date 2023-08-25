


/**
今天遇到指针函数和函数指针的问题，就直接把它彻底地分析了一遍，总结如下：
指针函数与函数指针表示方法的不同，千万不要混淆。最简单的辨别方式就是看函数名前面的指针*号有没有被括号（）包含，如果被包含就是函数指针，反之则是指针函数。
主要的区别是一个是指针变量，一个是函数。在使用是必要要搞清楚才能正确使用。
*/

// 下面案例是 函数指针
// 关键词，带括号，关注指针


#include<stdio.h>


int arr(int a, int b) { return 0; }
int brr(int a, int b) { return 1; }

int main()
{
	int (*frr)(int, int);//这里就是函数指针 
    int (*frr2)(int, int);
    frr=arr;
    frr2=brr;


    int res= (*frr)(2,3);
    int res2  = frr2(3,4);

    printf("%d\n",res);
    printf("%d\n",res2);
	return 0;
}
