

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * @param str string字符串 待判断的字符串
 * @return bool布尔型
 */
#include<stdbool.h>
#include<stdio.h>
bool judge(char* str ) {
    // write code here
    char* head =str;
    char* tail =str;
    while(*tail!='\0') {
        tail++;
    }
    tail--;

    while(head<tail){
        if(*head++ != *tail--) {
            return false;
        }
    }
    return true;
}


int main(){

    char* str="aba";
    printf("%d",judge(str));
    return 0;
}
