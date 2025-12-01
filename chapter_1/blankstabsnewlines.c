#include <stdio.h>

int main(){
    int b,t,nl;
    int c;
    b =0;
    t =0;
    nl =0;
    while ((c=getchar())!=EOF)
        if(c==' ')
            b++;
        else if (c =='\t')
            t++;
         else if (c=='\n')
            nl++;
    
    printf("blanks: %d Tabs: %d Newlines: %d",b,t,nl);
}