#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXLINE 1000

void expand(char origin[], char expanded[]);
int expand_flag(char s[], int index);

int main(){
    char str[] = "-aa-z0-9";
    char expanded[MAXLINE];

    expand(str, expanded);
    printf("%s\n", expanded);

    return 0;
}

void expand(char origin[], char expanded[]){
    int i, j;
    j = 0;
    int expandable;
    char start, end;

    for(i = 0; i < strlen(origin); i++){
        expandable = expand_flag(origin, i);

        if(expandable){
            start = origin[i-1] + 1;
            end = origin[i+1];
            //printf("%c, %c\n", start, end);
            while(start < end){
                expanded[j] = start;
                //printf("%c\n", expanded[j]);
                start++;
                j++;
            }
        } else {
            expanded[j] = origin[i];
            j++;
            //printf("Hello?\n");
        }
    }
    expanded[j] = '\0';
}

int expand_flag(char s[], int index){
    int length = strlen(s);

    if(s[index] != '-')
        return 0;

    if(index == length - 1 || index == 0){
        return 0;
    } else if((isalpha(s[index-1]) || isdigit(s[index-1]))
            && (isalpha(s[index+1]) || isdigit(s[index+1]))){
        return 1;
    } else {
        return 0;
    }
}