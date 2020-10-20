#include <stdio.h>

void strcat_mine(char a[], char b[]);

int main(){
    char a[] = "Hello ";
    char b[] = "World!";

    strcat_mine(a, b);

    printf("%s\n", a);
}

void strcat_mine(char a[], char b[]){
    int i, j;
    i = j = 0;

    while(a[i] != '\0')
        i++;
    
    while((a[i++] = b[j++]) != '\0')
        ;
}