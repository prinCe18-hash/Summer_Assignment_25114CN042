#include <stdio.h>
int main() {
    char str[100];
    int length = 0;
    int start , end ;
    char temp;
    printf("Enter a string:");
    fgets(str , sizeof(str) , stdin);
    while(str[length] != '\0') {
        length++;
    }
    if(length > 0 && str[length-1] == '\n') {
        str[length-1] = '\0';
        length--;
    }
    start = 0;
    end = length-1 ;
    while(start<end) {
        temp=str[start];
        str[start]=str[end];
        str[end]=temp;
        start++;
        end--;
    }
    printf("Reversed string: %s\n" , str);
    return 0;
}

