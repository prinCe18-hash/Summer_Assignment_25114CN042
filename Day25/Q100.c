#include <stdio.h>
#include <string.h>

#define MAX_WORDS 5
#define MAX_LENGTH 50
void sortWordsByLength(char words[MAX_WORDS][MAX_LENGTH], int n) {
    char temp[MAX_LENGTH];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
             if (strlen(words[j]) > strlen(words[j + 1])) {
                 strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }
}int main() {
     char words[MAX_WORDS][MAX_LENGTH] = {
        "Elephant",
        "Cat",
        "Hippopotamus",
        "Dog",
        "Monkey"
    };

    printf("Words before sorting:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("- %s (Length: %lu)\n", words[i], strlen(words[i]));
    }
    sortWordsByLength(words, MAX_WORDS);

    printf("\nWords sorted by length:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("- %s (Length: %lu)\n", words[i], strlen(words[i]));
    }

    return 0;
}