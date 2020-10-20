#include <stdio.h>

void squeeze(char[], int);

int main(){
    char s[] = "Hello World";
    char c = 'l';

    squeeze(s, c);
}

void squeeze(char str[], int c){
    int i, j;

    for(i = j = 0; str[i] != '\0'; i++){
        if(str[i] != c){
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    printf("%s\n", str);
}