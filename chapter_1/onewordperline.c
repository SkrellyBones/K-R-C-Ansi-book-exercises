#include <stdio.h>

#define IN 1 //inside a word
#define OUT 0 // outside a word
/*Take a single line of input and print each word in its own line*/
int main(){
    int c,state;
    state = OUT;
     
    while ((c=getchar())!= EOF){
        if(c==' '){
            
            putchar('\n');
            state= OUT;  
        }
        else{
            putchar(c);
            state =IN;
        }

    }
    

}