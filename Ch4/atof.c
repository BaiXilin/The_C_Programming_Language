#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main(){
    char source[] = "  3.1415926";
    double receive;

    receive = atof(source);
    printf("%f\n", receive);
    return 0;
}

double atof(char s[]){
    int i, sign;
    double val, power;

    for(i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-')? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    
    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if(s[i] == '.')
        i++;
    for(power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return (sign * val / power);
}