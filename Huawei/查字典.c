
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 100
#define MAX_SIZE 100

int comp(const void *a, const void *b) {
	return strcmp(*(const char**)a, *(const char**)b);
}

void findWord(const char* p, const char**d, int s) {
	int f = 0;
	for(int i=0;i<s;i++) {
		if(strncmp(p,d[i],strlen(p))==0) {
			printf("%s\n",d[i]);
			f = 1;
		}
	}
	if(!f) {
		printf("-1\n");
	}
}

int main(int argc, char** argv) {
	char p[MAX_LEN];
	int s;
	char *d[MAX_SIZE];

	scanf("%s%d",p,&s);

	for(int i=0;i<s;i++) {
		d[i] = malloc(MAX_LEN*sizeof(char));
		scanf("%s",d[i]);
	}

	qsort(d,s,sizeof(char*),comp);
	findWord(p,(const char**)d, s);
	for(int i=0;i<s;i++) {
		free(d[i]);
	}

	return 0;
}