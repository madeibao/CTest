



#include<stdio.h>
#include<string.h>

int main() {


    //除了定义一个字符数组外，还可以直接定义一个字符指针存储字符串
    char *sentence = "Do not go gentle into that good night!";

    //此时可以做字符串的操作
    //输出
    printf("%s\n", sentence);

    //通过下标取字符
    printf("%c\n", sentence[0]);

    //获取字符串长度，其中 strlen 是 string.h 库中的方法
    printf("%d\n", strlen(sentence));



    return 0;
}
