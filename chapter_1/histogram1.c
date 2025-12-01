#include <stdio.h>
//Write a program to print a histogram of the lengths of words in its input. It is
//easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging
 // this is the horizontal orientation, hell nah im not doing a vertical orientation yet (i lied i figured it out most of the way)
int main(){
    int len[20];
    int i,c,j;
    int count =0;
    for (i = 0; i < 20; ++i){
        len[i] =0;
    }
     while ((c=getchar())!= EOF){
        if(c==' ' || c=='\t' || c== '\n'){
           if (count>0){ 
            ++len[count];
            }
            count =0;
              
        }
        else{
            ++count;
           
        }

    }
    int max = 0;
for (i = 1; i < 20; i++) {
    if (len[i] > max)
        max = len[i];
}
    
    for (j = max; j>=1; --j){
    for(i=1; i<20;++i){
        if (len[i] < j)
            printf("  ");
        else
            printf("| ");
            }
    printf("\n");
}
    

for (i = 1; i<20; ++i){
printf("%d ",i);
    }
}
