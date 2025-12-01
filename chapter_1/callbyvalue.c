
int power(int base, int n){
int p;
    for (p=1; n>0; --n)
        p=p*base;
    return p;
}
//the parameter n is a temporary variable, whatever is done to n has no effect on the argument that called power
//we can have a function modify a variable in a calling routine
//we do this with pointers

