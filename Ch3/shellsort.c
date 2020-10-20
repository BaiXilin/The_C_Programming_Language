#include <stdio.h>

void shellsort(int v[], int n);

int main(){
    int v[10] = {9,8,7,6,5,4,3,2,1,0};
    shellsort(v, 10);

    for(int i = 0; i < 10; i++){
        printf("%d\t", v[i]);
    }
    printf("\n");

    return 0;
}

void shellsort(int v[], int n){
    int gap, i, j, temp;

    for(gap = n/2; gap > 0; gap /= 2){
        for(i = gap; i < n; i++){
            for(j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}