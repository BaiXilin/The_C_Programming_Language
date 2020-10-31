#include <stdio.h>

int strlen_(char *s){
    int i;
    for(i = 0; *s != '\0'; s++)
        i++;
    return i;
}

int strlen_pointer_imple(char *s){
    char *p = s;

    while(*p != '\0')
        p++;
    
    return p - s;
}

int main(){
    char s[] = "Hello World";
    int length;

    //length = strlen_(s);
    length = strlen_pointer_imple(s);
    printf("String \"%s\" is %d long.\n", s, length);

    return 0;
}