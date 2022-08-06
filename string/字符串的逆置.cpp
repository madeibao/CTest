
#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

char* reverse(char* str) {

	int i =0, j = strlen(str)-1;
	while(i<j) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}

	return str;
}

int main(){

    char str[] ={'a','b','c','\0'};
    char* str2 = reverse(str);
    printf("%s", str2);
    return 0;
}
