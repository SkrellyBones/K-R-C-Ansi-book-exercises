#include <stdio.h>
int main() {
    int c,i;
    int s[1000];
    int lim = 1000;
    for (i = 0; i < lim - 1;){
        if( (c = getchar()) != '\n')
            if( c != EOF){
                s[i] = c;
                ++i;
            }
    }
}
