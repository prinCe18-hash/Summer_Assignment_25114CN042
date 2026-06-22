#include <stdio.h>
#include <string.h>
#define MAX_CHARS 256
void countCharacterFrequency(char str[]) {
    int frequency[MAX_CHARS] = {0};
    int i = 0;
    while(str[i] != '\0') {
        if(str[i] != '\n') {
            frequency[(unsigned char)str[i]]++;
        }
        i++;
    }
    printf("\nCharacter Frequencies:\n");
    for(i=0 ; i<MAX_CHARS; i++){
        if(frequency[i]>0) {
            if(i == ' '){
                printf("[Spaces] : %d\n" ,frequency[i]);
            } else {
                 printf("'%c' : %d\n" , i ,frequency[i]);
            }
        }
    }
}
int main() {
    char str[100];
    printf("Enter a string:");
    fgets(str , sizeof(str) , stdin);
    countCharacterFrequency(str);
    return 0;
}


