

/**
	将一个句子按照单词为单位，逆序打印。

*/

#include <stdio.h>
#define DEBUG() printf("%s %s %d\n",__FILE__,__FUNCTION__,__LINE__)

void ReverseWord(char *m,char *n)//将指针P与指针q之间的所有字符逆序
{
	while(m < n)
	{
		char t ;
		t = *n;
		*n = *m;
		*m = t;
		m++;
		n--;//和正常的数据交换一样，可以引入第三方，注意地址的变化
	}
}

char *ReverseSentence(char *s)//对字符串中的每个单词进行逆序排列，形成正序的单词
{
	char *p = s;//指向单词的首字符
	char *q = s;//指向'\0'或' '，意为单词结束或字符串结束

	while(*q != '\0')
	{
		if(*q == ' ')
		{
			ReverseWord(p, q - 1);//对第一个单词进行逆序排列,同时注意，这是个函数，形参不能改变实参，p ,q 变量值不变
			q++ ;
			p = q;//q指向下一个单词的首字符
		}
		else
			q++;//q指向空格或'\0'
	}

	ReverseWord(p,q - 1);//交换最后一个单词
	ReverseWord(s,q - 1);//对整个句子逆序

	return s;

}

int main()
{
	char a[] = "I love China";//只能能数组存放字符串，如果将char *p = "I love China",p指向的是代码段，会出现段错误。
	char *str2;

	str2 = ReverseSentence(a);
	printf("After reversing,the string is:%s\n",str2);

	return 0;
}
