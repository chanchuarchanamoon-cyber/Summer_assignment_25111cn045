#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator function for qsort
int compareWords(const void *a, const void *b) {
    
    const char *wordA = *(const char **)a;
    const char *wordB = *(const char **)b;
    
    size_t lenA = strlen(wordA);
    size_t lenB = strlen(wordB);
    
    // 1. Primary Sort: By length (ascending)
    if (lenA != lenB) {
        return (lenA > lenB) - (lenA < lenB); 
    }
    
    
    return strcmp(wordA, wordB);
}

int main() {
    const char *words[] = {
        "apple", "banana", "kiwi", "pear", "fig", "date", "cherry", "grape"
    };
    
    
    int numWords = sizeof(words) / sizeof(words[0]);
    
    printf("Original list of words:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s ", words[i]);
    }
    printf("\n\n");
    
    // Sort using the built-in qsort function
    qsort(words, numWords, sizeof(const char *), compareWords);
    
    printf("Sorted by length, then alphabetically:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
    
    return 0;
}