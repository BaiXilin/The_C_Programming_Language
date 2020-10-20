#include <stdio.h>

void squeeze(char[], char[]);

int main(){
    char a[] = "Hello World";
    char b[] = "ol";

    squeeze(a, b);

    printf("%s\n", a);
}

void squeeze(char a[], char b[]){
    int i, j, k;
    
    for(k = 0; b[k] != '\0'; k++){
        for(i = j = 0; a[i] != '\0'; i++){
            if(a[i] != b[k]){
                a[j++] = a[i];
            }
        }
        a[j] = '\0';
    }
    //a[j] = '\0';
}