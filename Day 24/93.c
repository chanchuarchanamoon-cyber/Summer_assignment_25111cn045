#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool areRotations(char s1[], char s2[]) {
    int n = strlen(s1);

    // generate and check all possible rotations of s1
    for (int i = 0; i < n; ++i) {
        
        // if current rotation is equal to s2 return true
        if (strcmp(s1, s2) == 0)
            return true;

        // Right rotate s1
        char last = s1[n-1];
        for (int j = n-1; j > 0; j--) {
            s1[j] = s1[j-1];
        }
        s1[0] = last;
    }
    return false;
}

int main() {
    char s1[] = "aab";
    char s2[] = "aba";

    printf("%s", areRotations(s1, s2) ? "true" : "false");
    return 0;
}