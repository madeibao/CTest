




#include <stdio.h>

void cpystr(char *pss, char *pds) {
    while((*pds=*pss)!='\0') {
        pds++;
        pss++;
    }
}

void cprstr2(char *pss,char*pds){
    while( (*pds++=*pss++) != '\0' );
}

void cprstr3(char *pss,char*pds){
    while(*pds++ = *pss++);
}

int main() {
    char *pa = "Apple, Samsung, Xiaomi, Smartisan", b[100], *pb;
    pb=b;
    cprstr3(pa, pb);
    printf("string a=%s\nstring b=%s\n",pa, pb);

    return 0;
}
