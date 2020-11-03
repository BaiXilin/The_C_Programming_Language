#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

void push(double);
double pop(void);

int main(int argc, char *argv[]){
    double op2;
    int i;

    for(i = 1; i < argc; i++){
        switch(argv[i][0]){
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                push(atof(argv[i]));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '\'':
                op2 = pop();
                push(pop() / op2);
                break;
            default:
                printf("Unknown operator.\n");
                break;
        }
    }

    printf("%g\n", pop());
    return 0;
}

#define MAXVAL 100
int sp;
double val[MAXVAL];

void push(double in){
    if(sp < MAXVAL)
        val[sp++] = in;
    else
        printf("Stack full!\n"); 
}

double pop(void){
    if(sp >0)
        return val[--sp];
    else
    {
        printf("Stack empty!\n");
        return 0.0;
    }
}