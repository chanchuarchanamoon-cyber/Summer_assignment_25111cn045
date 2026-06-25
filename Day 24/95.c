#include <stdio.h>
#include <string.h>

int main() {
    char string[100] = "Hello Kurnool";
    int i = 0, letters = 0, longest = 0;

start:

    for (; string[i] !=' '; i++) {
        letters++;  
    }

    if (letters >= longest)
        longest = letters;

    if (string[i] == ' ') {
        letters = 0;
        i++;
        goto start;
    }

    printf("%d", longest);

    return 0;
} 