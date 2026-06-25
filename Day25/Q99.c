#include <stdio.h>
#include <string.h>
#define MAX_NAMES 5
#define MAX_LENGTH 50
void sortNames(char names[MAX_NAMES][MAX_LENGTH], int n) {
    char temp[MAX_LENGTH];
    for(int i=0 ; i<n-1 ; i++){
        for(int j=0 ; j<n-i-1 ; j++){
            if(strcmp(names[j] , names[j+1]) >0){
                strcpy(temp, names[j]);
                strcpy(names[j], names[j+1]);
                strcpy(names[j+1], temp);
            }
        }
    }
}
int main(){
    char names[MAX_NAMES][MAX_LENGTH] = {
        "Sophia",
        "Ethan",
        "Liam",
        "Ava",
        "Jackson"
    };
printf("Names in alphabetical order:\n");
for(int i=0 ; i<MAX_NAMES ; i++){
    printf("%s\n" , names[i]);
}
return 0;
}

