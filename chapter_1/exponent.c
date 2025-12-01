#include <stdio.h>
int power(int m, int n);
/* test power function */
int  main(){
    int i;
    for (i = 0; i<10; ++i)
	    printf("%d %d %d\n",i,power(2,i),power(-3,i));

    return 0;
}
/* power: raise base to nth power; n>=0*/
int power(int base,int n){
	int i,p;
	p = 1;
	for (i=1; i<=n; ++i)
		p=p*base;
	return p;
}
//the standard library contains pow(x,y) that computers x^y
//but this is our implementation from the text
//there is literally no way that i just spent FOUR FUCKING HOURS trying to get a linter bruh.
