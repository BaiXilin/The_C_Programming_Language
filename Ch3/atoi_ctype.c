#include <stdio.h>
#include <ctype.h>

int atoi(char s[]);

int main(){
    char number_str[] = "   -12345";
    int receive;

    receive = atoi(number_str);
    printf("%d\n", receive);
}

int atoi(char s[]){
    int i, n, sign;

    for(i = 0; isspace(s[i]); i++) //跳过空白符
        ;
    
    sign = (s[i] == '-') ? -1 : 1;
    //printf("Sign: %d\n", sign);

    if(s[i] == '+' || s[i] == '-') //跳过符号+/-
        i++;

    for(n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');

    return sign * n;
}