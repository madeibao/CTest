

#include<stdio.h>
#include<stdlib.h>

void change(int *pa) {
    *pa = 2;
}
int main() {

    int pa = 3;
    change(&pa);
    printf("%d \n",pa);
    return 0;
}

