#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(){
    int int_array[] = {0,1,2,3,4,5,6,7,8,9};
    int length = 10;
    int search_for = 9;

    int index_found = binsearch(search_for, int_array, length);

    printf("Number %d is found at index %d.\n", search_for, index_found);

    return 0;
}

int binsearch(int x, int v[], int n){
    int low, high, middle;
    low = 0;
    high = n - 1;

    while(low <= high){
        middle = (low+high)/2;
        if(x < v[middle]){
            high = middle - 1;
        } else if (x > v[middle]){
            low = middle + 1;
        } else {
            return middle;
        }
    }
    return -1;
}