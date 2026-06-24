#include <stdio.h>
#include <string.h>
#include <ctype.h>
void findLongestWord(const char *str) {
    int maxLen = 0;
    int maxStartIdx = 0;
    int maxLen = 0;
    int maxStartIdx = 0;
    int i=0 ;
    while (str[i] != '\0') {
        if(currentLen == 0) {
            currentStartIdx = 1;
        }
        currentLen++;
    } else {
        if (currentLen > maxLen){
            maxLen = currentLen;
            maxStartIdx = currentStartIdx;
        }
        currentLen = 0;
    }
i++;
}
if (currentLen > maxLen) {
    maxLen = currentLen;
    maxStartIdx = currentStartIdx;
}
if(maxLen > 0){
    printf("The longest word is:");
    for(int k = maxStartIdx; k<maxStartIdx + maxLen; k++) {
        putchar(str[k]);
    }
    printf("The longest word is:");
    for (int k = maxStartIdx; k < maxStartIdx + maxLen; k++){
        putchar(str[k]);
    }
    printf("\nLength: %d\n" , maxLen);
} else {
    printf("No valid words found.\n");
}
int main(){
    char sentence[256];
    printf("Enter a sentence:");
    if(fgets(sentence, sizeof(sentence), stdin) != NULL){
        sentence[len-1] = '\0';
    }
    return 0;
}



