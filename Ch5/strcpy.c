#include <stdio.h>

void strcpy_(char *s, char *t){
    while((*s = *t) != '\0'){
        s++;
        t++;
    }
}

void strcpy_better(char *s, char *t){
    while((*s++ = *t++) != '\0')
        ;
}

void strcpy_best(char *s, char *t){
    while((*s++ = *t++))
        ;
}

int main(){
    char *s;
    char *t = "Hello World!\n";

    strcpy_(s, t);
    printf("s = %s", s);

    return 0;
}