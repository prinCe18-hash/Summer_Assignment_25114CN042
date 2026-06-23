#include <stdio.h>
#include <string.h>
#define MAX_CHAR 256
char getMaxOccurringChar(char *str){
    int count[MAX_CHAR] = {0};
    int maxCount = 0;
    char maxChar = '\0';
    for(int i=0 ; str[i] != '\0' ; i++){
        count[(unsigned char)str[i]]++;
    }
for(int i=0 ; i<MAX_CHAR ; i++){
    if(count[i] > maxCount) {
        maxCount = count[i];
        maxChar = (char)i;
    }
}
return maxChar;
}
int main(){
    char str[256];
    if(fgets(str , sizeof(str) , stdin)){
        str[strcspn(str, "\n")] = '\0';
    }
    if(strlen(str) == 0){
        printf("The string is empty.\n");
        return 0;
    }
    char result = getMaxOccurringChar(str);
    printf("The maximum occuring character is : '%c'\n", result);
    return 0;
}

