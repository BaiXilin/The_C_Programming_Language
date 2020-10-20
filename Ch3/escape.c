#include <stdio.h>
#define MAXLINE 1000

void escape(char[], char[]);

int main(){
    char str[] = "Hello World!\n";
    char receive[MAXLINE];

    escape(str, receive);
    printf("%s\n", receive);

    return 0;
}

void escape(char ori[], char rec[]){
    int i, j;
    j = 0;
    for(i = 0; ori[i] != EOF; i++){
        switch(ori[i]){
            case '\n':
                rec[j] = '\\';
                j++;
                rec[j] = 'n';
                j++;
                break;
            case '\t':
                rec[j] = '\\';
                j++;
                rec[j] = 't';
                j++;
                break;
            default:
                rec[j] = ori[i];
                j++;
                break;
        }
    }
    rec[j] = '\0';
}