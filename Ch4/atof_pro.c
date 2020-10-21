#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main(){
    char source[] = "  -102E-1"; //-10.2
    double receive;

    receive = atof(source);
    printf("%f\n", receive);
    return 0;
}

double atof(char s[]){
    int i, sign, mag_sign;
    double val, power, mag;
    i = 0;

    //前置空白符与正负号部分
    while(isspace(s[i]))
        i++;
    sign = (s[i] == '-') ? -1 : 1;
    
    if(s[i] == '+' || s[i] == '-')
        i++;

    //数字部分
    for(val = 0.0; isdigit(s[i]); i++){
        val = 10 * val + (s[i] - '0');
    }
    if(s[i] == '.')
        i++;
    for(power = 1.0; isdigit(s[i]); i++){
        val = 10 * val + (s[i] - '0');
        power *= 10;
    }

    //科学计数法部分
    if(s[i] == 'e' || s[i] == 'E')
        i++;
    mag_sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(mag = 1.0; isdigit(s[i]); i++)
        if(mag_sign == 1)
            mag *= 10;
        else
            mag /= 10;
 
    val = sign * val / power * mag;

    return val;
}