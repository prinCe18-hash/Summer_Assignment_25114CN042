#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void compressString(const char *src) {
    int len = strlen(src);
    if(len <= 1){
        printf("Compressed string: %s\n",src);
        return;
    }
    char *dest = (char *)malloc(sizeof(char)*(len*2+1));
    if(dest == NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    int i=0;
    int j=0;
    while(i<len){
        dest[j++] = src[i];
        int count = 1;
       while(i+1<len && src[i] == src[i+1]) {
        count++;
        i++;
       }
       int charsWritten = sprintf(&dest[j] , "%d" , count);
       j+=charsWritten;
       i++;
    }
    dest[j] = '\0';
    if(strlen(dest) < len) {
        printf("Compressed string: %s\n", dest);
    } else {
        printf("Compressed string : %s (Orignal kept as compression didnot save space)\n", src);
    }
    free(dest);
}
int main() {
    char str[100];
    printf("Enter a string to compress:");
    if (scanf("%99s", str) == 1) {
        compressString(str);
    }
    return 0;
}
