#include <stdio.h>
#include <string.h>
void removeDuplicates(char *str) {
    int seen[256] = {0};
    int readIndex = 0;
    int writeIndex = 0;
    while(str[readIndex] != '\0') {
        unsigned char currentChar = (unsigned char)str[readIndex];
        if (seen[currentChar] == 0){
            seen[currentChar] = 1;
            str[writeIndex] = str[readIndex];
            writeIndex++;
        }
        readIndex++;
    }
    str[writeIndex] = '\0';
}
int main() {
    char str[100];
    printf("Enter a string:");
    if(fgets(str, sizeof(str) , stdin) != NULL) {
        size_t len = strlen(str);
        if(len > 0 && str[len-1] == '\n'){
            str[len-1] = '\0';
        }
        removeDuplicates(str);
        printf("String after removing duplicates : %s\n", str);
    }
    return 0;
}



