#include <stdio.h>
#include <stdbool.h>
int countWords(char str[]) {
    int i=0;
    int wordCount=0;
    bool inWord = false;
    while(str[i] != '\0') {
        if(str[i] == ' ' ||str[i] == '\n' ||str[i] == '\t' ) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            wordCount++;
        } 
        i++;  
    }
    return wordCount;
}
int main() {
    char sentence[1000];
    printf("Enter a sentence:");
    fgets(sentence , sizeof(sentence) , stdin);
    int totalWords = countWords(sentence);
    printf("Total number of words: %d\n" , totalWords);
    return 0;
}

