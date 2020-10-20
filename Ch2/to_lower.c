#include <stdio.h>

int main(){
    char str[] = "HELLO WORld!";
    int i = 0;
    char c;

    while(str[i] != '\0'){
        str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? (str[i] - 'A' + 'a') : str[i];
        i++;
    }

    printf("%s\n", str);

    return 0;
}