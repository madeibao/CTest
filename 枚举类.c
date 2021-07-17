
#include<stdio.h>

typedef enum Temp { 
	E12 = 2,
	E13,
	E14 = 5,
	E15 = 5,
}ENum_m;

int main(int argc, char*argv[]) {

	enum Temp temp = E12;
	printf("%d\n",	temp);
	return 0;
}