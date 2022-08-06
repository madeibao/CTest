
#include<stdio.h>
#include<string.h>

void swap(char *a, char *b) {
    char c;

    c = *a;
    *a = *b;
    *b = c;
}

int isVowels(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return 1;
    }
    return 0;
}

char* reverseVowels(char * s) {
    int l = 0, r = strlen(s) - 1;

    while (l < r) {
        if (isVowels(s[l]) && isVowels(s[r])) {
            swap(s + l, s + r);
            l++;
            r--;
            continue;
        }
        if (!isVowels(s[l]))
            l++;
        if (!isVowels(s[r]))
            r--;
    }
    return s;
}

int main() {

    char ch[] ="hello";
    puts(reverseVowels(ch));
    return 0;
}
