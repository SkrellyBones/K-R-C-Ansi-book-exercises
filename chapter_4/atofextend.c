//extend atof to handle scientifc notation
#include <ctype.h>
double atof(char s[]){
    double val, power, exp_power;
    int i, sign, exp_sign, exponent;
    for(i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if(s[i] == '.')
        i++;
    for(power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if(s[i] == 'e' || s[i] == 'E'){
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if(s[i] == '+' || s[i] == '-')
            i++;
        for(exponent = 0; isdigit(s[i]); i++)
            exponent = 10 * exponent + (s[i] - '0');
        exp_power = 1.0;
        for(int j = 0; j < exponent; j++)
            exp_power *= 10;
        if(exp_sign == -1)
            val /= exp_power;
        else
            val *= exp_power;
    }
    return sign * val / power;
}
