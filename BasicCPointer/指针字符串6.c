

#include<stdio.h>
#include<string.h>
char *mystrcpy(char *dest,char *src);
char *mystrcat(char *dest,char *src);
int mystrlen(char* src);
int mystrcmp(char* str1,char* str2);

int main()
{
    char a[] = {'h','e','l','l','o'}; //字符数组
    printf("%s\n",a);  //字符数组只能用for循环打印,否则后面会出现乱码
    char b[] = {'h','e','l','l','o','\0'}; // 以'\0'结尾的字符数组就是一个字符串，可以用%s完美打印
    printf("%s\n",b);
    char c[] = "hello,my name is trump!,I'm the spy of CN" ; //更方便快捷的字符串初始化方式，若想表达一个字符串，用它！
    printf("%s\n",c);
    //需要注意的是，字符串的结束符会占一个字节,比如 char d[3] = "123";会报错

    //字符串函数
    //一、strcpy
    char stra[15];
    char strb[] = "223333";
    strcpy(stra,strb);
    printf("%s\n",stra);
    mystrcpy(stra,strb);
    printf("%s\n",stra);

    //二、strcat
    char strc[] = "大家好，我是大sao，";
    char strd[] = "今天咱们吃一顿好的！";
    strcat(strc,strd);
    printf("%s\n",strc);
    mystrcat(strc,strd); //再吃一顿好的。。。天天吃好的！
    printf("%s\n",strc);
    //三、strlen
    char stre[] = "xyyz";
    int n = strlen(stre);
    printf("n=%d\n",n);
    int n2 = mystrlen(stre);
    printf("n2=%d\n",n2);
    //四、strcmp
    char t1[] = "hello";
    char t2[] = "hell";
    printf("%d\n",strcmp(t1,t2));
    printf("%d\n",mystrcmp(t1,t2));

    return 0;
}
//函数功能：将源字符串src拷贝到目标字符串dest中，且dest中的字符串被删除
//函数输入： 两个字符指针，指向传入dest以及src的地址，
//函数返回:  指向拷贝后的字符串指针dest
char *mystrcpy(char *dest,char *src)
{
    char *pSrc = src;
    char *pDest = dest;
    while (*pSrc!=0)
    {
        *pDest = *pSrc;
        pDest++;
        pSrc++;
    }
    *pDest = 0;
    return dest;

}
//函数功能：将src字符串连接到dest字符串后面
//函数输入： 两个字符指针，指向传入dest以及src的地址，
//函数返回:  指向连接后的字符串指针dest
char *mystrcat(char *dest,char *src)
{
    char *pSrc = src;
    char *pDest = dest;
    //先将目标字符串指针移至dest的结束符'\0'位置
    while (*pDest!=0)
    {
        pDest++;
    }
    while (*pSrc!=0)
    {
        *(pDest++) = *(pSrc++);
    }
    *pDest = '\0';
    return dest;
}

//函数功能：输出字符串长度，不包括结束符'\0'
int mystrlen(char* src)
{
    char *p = src;
    int n=0;
    while (*p!=0)
    {
        n++;
        p++;
    }
    return n;
}

//函数功能：比较两个字符串(的ASCII值），str1>str2,返回1，str1<str2,返回-1，str1=str2,返回0，
int mystrcmp(char* str1,char* str2)
{
    char *p1 = str1;
    char *p2 = str2;
    while (*p1!=0)
    {
        if(*p1==*p2)
        {
            p1++;
            p2++;
        }
        else if (*p1>*p2)
        {
            return 1;
        }
        else if(*p1<*p2)
        {
            return -1;
        }
    }
    if(*p2==0)
        return 0;
    else
         return -1;

}
