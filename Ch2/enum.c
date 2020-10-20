#include <stdio.h>

int main(){
    enum year {JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

    for(int i = JAN; i <= DEC; i++){
        printf("%d ", i);
    }
}