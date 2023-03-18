


bit也就是我们不一定听说过的比特，大名鼎鼎的比特币就是以此命名的。它的简写为小写字母 “b” 。
作为信息技术的最基本存储单元，因为比特实在太小了，所以大家生活中并不是经常听到。
那么 bit 是什么呢？电脑是以二进制存储以及发送接收数据的。二进制的一位，就叫做 1 bit。
也就是说 bit 的含义就是二进制数中的一个数位，即  “0” 或者 "1"。


bit  = 0  或者 1

Byte 字节 byte 字节

1 Byte = 8 bit

1 Byte = 1111 1111  8 位表示

1KB = 1024 Byte (B)

1MB = 1024 KB 

1GB = 1024 1MB



十六进制，8进制表示
都需要先转为十进制表示
然后十进制转化为二进制表示


int num = 0x12;
转为十进制 2*16^0+1*16^1 = 18;
18转化为十进制表示为 0001 0010

----------------------------------------------------------------------------

#include<stdio.h>
void printBinary(unsigned int n) {
    if (n > 1) {
        printBinary(n / 2);
    }
    printf("%d", n % 2);
}

int main() {

    int num = 15;
    printf("十六进制 %x \n", num);
    printf("  八进制 %o \n", num);
    printf("  十进制 %d \n", num);
    printf("  二进制+ 0b");
    printBinary(num);
    printf("\n");
    return 0;
}





#include <stdio.h>

int main() {
    char hex[17];
    long int decimal, binary;
    int i = 0, digit;

    // 读取十六进制数
    printf("请输入一个十六进制数:\n");
    scanf("%s", hex);

    // 将十六进制数转换为十进制数
    decimal = 0;
    while (hex[i] != '\0') {
        digit = hex[i];
        if (digit >= '0' && digit <= '9') {
            digit -= '0';
        } else if (digit >= 'a' && digit <='f') {
            digit -= 'a' - 10;
        } else if (digit >= 'A' && digit <='F') {
            digit -= 'A' - 10;
        } else {
            printf("非法输入.\n");
            return 0;
        }
        decimal = decimal * 16 + digit;
        i++;
    }

    // 将十进制数转换为二进制数
    i = 0;
    while (decimal > 0) {
        binary = decimal % 2;
        decimal /= 2;
        hex[i] = binary + '0';
        i++;
    }
    hex[i] = '\0';

    // 反转二进制数
    for (int j = 0; j < i / 2; j++) {
        digit = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = digit;
    }

    printf("该数的二进制表示为: %s\n", hex);

    return 0;
}

