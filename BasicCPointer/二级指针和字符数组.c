


#include <stdio.h>

int main() {
    char a[3][20] = {
        "You_are_a_girl",
        "I_am_a_boy",
        "We_are_friends"
    };
    char *p = a[0];
    char **ptr = &p;

    for (int i = 0; i < 3; i++) {
        printf("%s\n", *(ptr + i));
    }

    return 0;
}