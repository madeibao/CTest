

#include<stdio.h>


int main(int argc, char** argv) {
	int a[3][3], *p, i;
	p = &a[0][0];
	for(int i=0;i<9;i++) {
		p[i] = i+1;
	}

	printf("%d",a[1][2]);
	return 0;
}