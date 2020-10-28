#include <stdio.h>
#include <string.h>

void reverse(char s[], int left, int right){
    if(left >= right)
        return;
    
    void swap(char s[], int i, int j);

    swap(s, left, right);
    left++;
    right--;
    reverse(s, left, right);
}

void swap(char s[], int i, int j){
    int temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}


int main(){
    char arr[] = "Hello World!";

    reverse(arr, 0, strlen(arr) - 1);

    printf("%s\n", arr);
    return 0;
}