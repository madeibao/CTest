


/**
 * 反转字符串
 * @param str string字符串
 * @return string字符串
 */

#include <stdio.h>

char* solve(char* str) {
    int i=strlen(str)-1,j=0;
    char temp;
    while(i>j)
    {
        temp=str[i];
        str[i--]=str[j];
        str[j++]=temp;
    }
    return str;
}


int main() {

	char str[]= {'a','b','c','\0'};
	char* str2;
	str2 = solve(str);
	printf("%s", str2);

	return 0;
}




