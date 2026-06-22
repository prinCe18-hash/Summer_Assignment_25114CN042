#include <stdio.h>
void removeSpaces(char str[]){
    int i=0 ;
    int j=0 ;
    while (str[i] != '\0') {
        if(str[i] != ' ' && str[i] != '\t') {
            str[j] = str[i]; 
            j++;
        }
        i++;
    }
    str[j] = '\0';
}
int main() {
    char str[100];
    printf("Enter a string:");
    fgets(str , sizeof(str) , stdin);
removeSpaces(str);
printf("String after removing spaces: %s", str);
return 0;
}

