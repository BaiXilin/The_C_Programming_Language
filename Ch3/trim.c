#include <string.h>
#include <stdio.h>

int trim(char s[]);

int main(){
    char str[] = "Hello     \n\t\n";
    int length = trim(str);

    printf("The length ater trim is %d.\n", length+1);
    return 0;
}

int trim(char s[]){
    int n;
    for(n = strlen(s) - 1; n >= 0; n--){
        if(s[n] != '\n' && s[n] != '\t' && s[n] != ' '){
            break;
        }
    }
    s[n+1] = '\0';
    return n;
}