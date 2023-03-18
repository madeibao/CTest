


#include<stdio.h>

int main() {
	const char *str="I love China!",*str1;
	str1=str;
	printf("%s\n",str);
	for(  ;*str!='\0';) {
		printf("%c",*str++);
    }

	printf("\n");
	str1+=7;
	printf("%s\n",str1);
	return 0;
}
