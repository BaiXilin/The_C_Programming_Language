#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

int getint(int *pn){
    int c, sign, sign_flag;

    while(isspace(c = getch()))
        ;
    
    if(!isdigit(c = getch()) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0; //输入不是数字
    }

    sign = (c == '-') ? -1 : 1;

    if(c == '+' || c == '-')
        c = getch();
    
    
    //Practice 5-1
    if((sign_flag = (c == '+' || c == '-')))
        c = getch();
    
    if(!isdigit(c)){
        ungetch(c);
        return 0;
    }

    for(*pn = 0; isdigit(c); c = getch()){
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;

    if(c != EOF)
        ungetch(c);
    return c;
}

//超前读取与缓冲区
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0; //buf中下一个空白位置

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if(bufp >= BUFSIZE)
        printf("Error: Ungetch has too many characters\n");
    else
        buf[bufp++] = c;
}

#define SIZE 5

int main(){
    int n, array[SIZE], getint(int *);

    for(n = 0; n < SIZE && getint(&array[n]) != EOF; n++){
        ;
    }
    //printf("n = %d\n", n);

    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}