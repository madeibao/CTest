

#include<stdio.h>
#include<string.h>

int main() {

    //定义字符数组 sentence 和 word，给 sentence 赋初值
    char sentence[] = "Do not go gentle into that good night!", word[100];

    //定义字符指针，指向 word
    char *ch = word;
    int i;

    //循环赋值 ,字符串结尾符号 '\0'
    for(i = 0; sentence[i]!= '\0'; i++){
        *(ch + i) = sentence[i];
    }

    //在当 i 等于 sentence 的长度（sentence 的长度不包含'\0'）时，
    //i 继续自增，此时判断 sentence[0] != '\0'不符合，跳出循环，则 i 比 sentence 长度大 1
    *(ch + i) = '\0';

    //输出字符串，因为 ch 指向 word，所以输出结果是一样的
    printf("ch =   %s \n", ch);
    printf("word = %s \n", word);

    return 0;
}
