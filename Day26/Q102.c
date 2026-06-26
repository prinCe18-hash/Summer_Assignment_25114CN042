#include <stdio.h>
int main() {
    int age;
    printf("Please enter your age:");
    if(scanf("%d" , &age) != 1){
        printf("\n Error : Invalid output , Please enter a numerical age.\n");
        return 1;
    }
    if(age<0){
        printf("\n Error : Age cant be negative . Enter a valid age.");
    } else if (age>=18){
        printf("\n Congartulations ! You are eligible to vote.\n");
    } else {
        printf("\n Sorry, you are not eligible to vote yet.\n");
    }
    return 0;
}
