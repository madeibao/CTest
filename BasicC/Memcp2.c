
// memcpy函数是C/C++语言中的一个用于内存复制的函数，声明在 string.h 中（C++是 cstring）。其原型是：

// void *memcpy(void *destin, void *source, unsigned n);
// 作用是：以source指向的地址为起点，将连续的n个字节数据，复制到以destin指向的地址为起点的内存中。
// 函数有三个参数，第一个是目标地址，第二个是源地址，第三个是数据长度。
// 使用memcpy函数时，需要注意：

// 数据长度（第三个参数）的单位是字节（1byte = 8bit）。
// 注意该函数有一个返回值，类型是void*，是一个指向destin的指针。

#include<stdio.h>
#include<string.h>


int main() {

	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[5] = { 0 };
	memcpy(arr2, arr1, 20);
    
    int i =0;
    for(int i=0;i<5;i++) {
        printf("%d ",arr2[i]);
    }
    printf("\n");
	return 0;
}
