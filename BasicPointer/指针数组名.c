

// “%p”中的p是pointer（指针）的缩写。%p是打印地址的, 而%x是以十六进制形式打印。
// %p是打印地址（指针地址）的，是十六进制的形式，但是会全部打完，即有多少位打印多少位。

// 32位编译器的指针变量为4个字节(32位)，64位编译器的指针变量为8个字节(64位)。

// 所以，在32位编译器下，使用%p打印指针变量，则会显示32位的地址（16进制的）；在64位编译器下，使用%p打印指针变量，则会显示64位的地址（16进制的），左边空缺的会补0。

// %x：无符号十六进制整数(字母小写，不像上面指针地址那样补零)

// %X：无符号十六进制整数(字母大写，不像上面指针那样补零)

// %x、%X和%p的相同点都是16进制，不同点是%p按编译器位数长短（32位/64位）输出地址，不够的补零

#include<stdio.h>

int main() {

    int b[10] = {0,1};
    printf("%d\n",b);
    printf("%d\n",&b);

    int a = 1;       // 定义一个int型变量
    int *p = &a;     // 定义一个int型指针p，&a表示对a取地址，指针p的内容是a的地址
    // int  *p;   p = &a;    // 第二行也可以这样写，意思一样
    printf("%p\n", &a);      // 打印a的地址
    printf("%p\n", *p);       // 打印指针p指向的地址


    printf("--------------------------------\n");

    char nums[5] = {1, 2, 3, 4, 5};  // 定义一个char型数组，这里的a实质上是一个指针，指向这个数组的首元素a[0]的指针
	char *pa = nums;
	printf("%d\n", *pa);        // 输出1 --> nums[0]
	printf("%d\n", *(pa + 1));  // 输出2 --> nums[1]
    return 0;
}
