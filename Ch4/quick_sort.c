#include <stdio.h>
#include <stdlib.h>

void quick_sort(int v[], int left, int right){
    int i, last;
    void swap(int v[], int i, int j);

    if(left >= right){
        return;
    }

    swap(v, left, (left+right)/2);
    last = left;

    for(i = left+1; i <= right; i++){
        if(v[i] < v[left])
            swap(v, ++last, i);
    }
    swap(v, left, last);
    quick_sort(v, left, last - 1);
    quick_sort(v, last + 1, right);
}

void swap(int v[], int i, int j){
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main(){
    int seq[15];

    for(int i = 0; i < 15; i++){
        seq[i] = rand();
        //printf("%d ", seq[i]);
    }
    //printf("\n");
    
    quick_sort(seq, 0, 14);

    for(int i = 0; i < 15; i++){
        printf("%d ", seq[i]);
    }
    printf("\n");
    return 0;
}