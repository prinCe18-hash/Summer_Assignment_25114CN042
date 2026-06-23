#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_CHAR 256
bool areAnagrams(char *str1 , char *str2) {
    int count[MAX_CHAR]= {0};
    int i;
    if(strlen(str1) != strlen(str2)) {
        return false ;
    }
    for (i=0 ; str1[i] != '\0' ; i++){
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
    }
    for(i=0 ; i<MAX_CHAR ; i++){
        if(count[i] != 0){
            return false;
        }
    }
    return true ;
}
int main(){
   char str1[100];
    char str2[100];
    printf("Enter first string :");
    if(fgets(str1, sizeof(str1) , stdin)){
        str1[strcspn(str1, "\n")] = '\0';
    }
    printf("Enter second string :");
    if(fgets(str2, sizeof(str2) , stdin)){
        str1[strcspn(str2, "\n")] = '\0';
    }
    if (areAnagrams(str1 , str2)){
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }
    return 0;
}


