
#include <stdio.h>

int main(void) {
	char *arr[3] = {"abc", "def", "ghi"};
	char *pArr = arr[0];

	printf("字符串数组arr的每个字符串元素是:  ");
	for(int index = 0; index < 3; index++) {
		printf("%s ", arr[index]);
	}

	printf("\n");
	printf("字符串数组arr第一个字符串的每个元素是:  ");
	for(int index = 0; index < 3; index++) {
		printf("%c ", *(pArr + index) );
	}

	printf("\n");
	return 0;
}



