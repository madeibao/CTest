


#include<iostream>
using namespace std;
void swap(int &a, int &b);
int main(int argc, char* argv[]) {
    int a= 3;
    int b= 5;

    cout<<" 交换之前的操作内容为"<<endl;
    cout<<a<<" "<<b<<"  "<<endl;

    swap(a,b);

    cout<<" 交换之后的操作内容为"<<endl;
    cout<<a<<" "<<b<<"  "<<endl;
}

void swap(int &a,int &b) {
    int temp = a;
    a= b;
    b= temp;
}







