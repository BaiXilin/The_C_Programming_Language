#include <stdio.h>

int htoi(char []);

int main(){
    char hex[] = "123ABC";
    int dec;

    dec = htoi(hex);
    printf("%d\n", dec);
}

int htoi(char hex[]){
    int dec = 0;

    for(int i = 0; hex[i] != '\0'; i++){
        if(hex[i] >= '0' && hex[i] <= '9'){
            dec = dec * 16 + (hex[i] - '0');
        } else if(hex[i] >= 'a' && hex[i] <= 'f'){
            dec = dec * 16 + (hex[i] - 'a' + 10);
        } else if(hex[i] >= 'A' && hex[i] <= 'F'){
            dec = dec * 16 + (hex[i] - 'A' + 10);
        } else {
            printf("Exit with error code -1. Input contained illegal hexadecimal number.\n");
            return -1;
        }
    }
    return dec;
}