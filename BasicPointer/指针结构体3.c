

#include <stdio.h>
#include<string.h>

typedef struct ListNode {
    int a;
    int b;
}Node;


int main() {

    Node data;
    data.a = 2;
    data.b = 3;
    struct ListNode *p=&data;


    printf("%d\n",p->a);
    printf("%d\n",p->b);
    return 0;
}
