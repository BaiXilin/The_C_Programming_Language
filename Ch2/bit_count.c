#include <stdio.h>

int bitcount(unsigned x);

int main(){
    int input;
    input = 12345;

    int num_of_bit;
    num_of_bit = bitcount(input);

    printf("The number of bit 1 in %d is %d.\n", input, num_of_bit);
    return 0;
}

int bitcount(unsigned x){
    int b;

    for(b = 0; x != 0; x >>= 1){
        if(x & 01)
            b++;
    }

    return b;
}