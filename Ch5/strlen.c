#include <stdio.h>

int strlen_(char *s){
    int i;
    for(i = 0; *s != '\0'; s++)
        i++;
    return i;
}

int main(){
    char s[] = "Hello World";
    int length;

    length = strlen_(s);
    printf("String \"%s\" is %d long.\n", s, length);

    return 0;
}