



#include <stdio.h>

int main() {
    char str[20], *ps;
    int i;
    printf("Input a string: ");
    ps = str;
    scanf("%s", ps);
    for(i=0; ps[i]!='\0'; i++){
        if(ps[i]=='k'){
            printf("There is a 'k' in the string!\n");
            break;
        }
    }
   
    if(ps[i]=='\0') printf("There is no 'k' in the string\n");

    return 0;
}

