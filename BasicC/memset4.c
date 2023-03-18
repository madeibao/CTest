



#include<stdio.h>
#include<string.h>

int main(){
    int i=0;
    char array[100];
    scanf("%s",&array);
    // gets(array);
    memset(array, '\0',sizeof(array));
    for(i=0; i<4; i++){
        printf("%c ",array[i]);
    }
    printf("\n");
    return 0;
}
