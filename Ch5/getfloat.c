#include <ctype.h>
#include <stdio.h>
#include <math.h>

int getch(void);
void ungetch(int);

double getint(double *pn){
    int c, sign_flag;
    double sign, power = 1;

    while(isspace(c = getch()))
        ;
    
    if(!isdigit(c = getch()) && c != EOF && c != '+' && c != '-' && c != '.'){
        ungetch(c);
        return 0; //输入不是数字
    }

    sign = (c == '-') ? -1 : 1;

    if(c == '+' || c == '-')
        c = getch();
    
    if((sign_flag = (c == '+' || c == '-'))){
        c = getch();
        if(!isdigit(c) && c != '.'){
            if(c == EOF){
                return EOF;
            }
            else{
                ungetch(c);
                return 0;
            }
        }
    }

    int fraction = 0, digits = 0;
    for (*pn = 0; isdigit(c) || c == '.' ; c = getch()) {
        if (c == '.') {
            fraction = 1;
        } else {
            if (!fraction) {
                *pn = 10 * *pn + (c - '0');
            } else {
                *pn = *pn + ((c - '0') / pow(10, fraction));
                fraction++;
            }
        digits++;
        }
    }

    *pn *= sign;

    if(c == EOF)
        return EOF;
    else{
        ungetch(c);
        return (digits) ? c : 0;
    }
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
    int n; 
    double array[SIZE], getint(double *);

    for(n = 0; n < SIZE && getint(&array[n]) != EOF; n++){
        ;
    }
    //printf("n = %d\n", n);

    for(int i = 0; i < n; i++){
        printf("%f ", array[i]);
    }
    printf("\n");
    return 0;
}