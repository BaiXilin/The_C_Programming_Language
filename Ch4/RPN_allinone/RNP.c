#include <stdio.h>
#include <stdlib.h> //使用atof函数
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

int main(){
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF){
        switch(type){
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();        //减法中交换律不成立，注意区分左右操作数
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();        //除法同理
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Undefined\n");
            case '%':
                op2 = pop();
                push(pop() % op2);
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Error: Unknown Command %s.\n", s);
        }
    }
    return 0;
}

//将值压入/取出栈
#define MAXVAL 100      //栈val的最大深度

int sp = 0;             //下一个空闲栈位置
double val[MAXVAL];     //值栈

void push(double d){
    if(sp < MAXVAL)
        val[sp++] = d;
    else
        printf("Error: Stack Full. Push Failed.\n");
}

double pop(void){
    if(sp > 0)
        return val[--sp];
    else
        printf("Error: Stack Empty\n");
        return 0.0;
}

//获取下一个数值/运算符
int getch(void);
void ungetch(int);

int getop(char s[]){
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        //printf("%c\n", c);
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    i = 0;
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()))
            //printf("%d\n", i);
            ;
    if(c == '.')
        while(isdigit(s[++i] = c = getch()))
            //printf("%d\n", i);
            ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    
    return NUMBER;
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