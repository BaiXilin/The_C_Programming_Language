#include <stdio.h>

void swap(int *pa, int *pb){
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main(){
    int a = 0;
    int b = 100;

    swap(&a, &b);

    printf("a stores %d\n", a);
    printf("b stores %d\n", b);

    return 0;
}