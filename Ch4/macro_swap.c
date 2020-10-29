#include <stdio.h>
#define swap(t, x, y) {t temp = x; x = y; y = temp;}

int main(){
    char a = 'a';
    char b = 'b';

    swap(char, a, b);
    printf("a stores %c\n", a);
    printf("b stores %c\n", b);

    return 0;
}