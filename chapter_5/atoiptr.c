/*atio: convert s to integer*/
int atoi(char *s){
    int n =0;
    char *p = s;
    while (*p >= '0' && *p <='9')
        n = 10*n+(*p++-'0');
    return n;
}
