#include <stdio.h>

int string_to_int(char []);
void lower_case(char []);

int main(){
    char s[] = "HeLLo WORld!";
    int i = 0;

    i = string_to_int(s);
    printf("%d\n", i);
 
    lower_case(s);
    
}

int string_to_int(char str[]){
    int i, n;
    for(i = 0; str[i] >= '0' && str[i] <= '9'; i++){
        n = 10 * n + (str[i] - '0');
    }
    return n;
}

void lower_case(char str[]){
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            printf("%c", (str[i] - 'A' + 'a'));
        } else {
            printf("%c", str[i]);
        }
    }
    printf("%c", '\n');
}