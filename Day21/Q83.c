#include <stdio.h>
int main(){
    char str[100];
    int vowels = 0 , consonants=0;
    int i =0;
    printf("Enter a string:");
    fgets(str , sizeof(str), stdin);
    while(str[i] != '\0') {
        char ch = str[i];
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' ||ch == 'E' ||ch == 'I' ||ch == '0' ||ch == 'U' ) {
                vowels++;
            }
            else {
                consonants++;
            }
        }
        i++;
    }
    printf("Vowel is:%d\n" , vowels);
    printf("Consonants is:%d\n" , consonants);
return 0;
}

