

/**

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void swap(int a, int b) {
   int temp =0;
   temp = a;
   a = b;
   b = temp;

}

void swap2(int *a, int *b) {
   int c =0;
   c = *a;
   *a = *b;
   *b = c;
}

void swap3(int &a,int &b) {
    int c =0;
    c = a;
    a= b;
    b= c;

}

int main() {

    int x = 1;
	int y = 2;
	swap(x, y);
	cout << x << "," << y << endl;

	swap2(&x, &y);
	cout << x << "," << y << endl;

	swap3(x, y);
	cout << x << "," << y << endl;
}

*/
