#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_CHAR 256
char findFirstRepeating(char *str){
    bool visited[MAX_CHAR] = {false};
    for(int i=0 ; str[i] != '\0' ; i++){
        unsigned char ch = (unsigned char)str[i];
        if(visited[ch]){
            return str[i];
        }
        visited[ch] = true;
    }
    return '\0' ;
}
int main() {
    char str[100];
    printf("Enter a string:");
    if(fgets(str, sizeof(str), stdin)){
        str[strcspn(str , "\n")] = '\0';
    }
    char result = findFirstRepeating(str);
    if(result != '\0'){
        printf("The first repeating character is : '%c'\n", result);
    } else {
        printf("No repeating characters found.\n");
        return 0;
    }
}


