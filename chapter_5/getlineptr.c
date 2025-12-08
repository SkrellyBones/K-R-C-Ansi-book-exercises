#include <stdio.h>
#define MAXLINE 1000
int getLine(char *line, int maxline);
void copy(char *to, char *from);
int main(){
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    max =0;
    while ((len = getLine(line,MAXLINE))>0)
        if (len >max){
            max = len;
            copy(longest, line);
        }
    if (max >0) //there was a line
        printf("%s", longest);
    return 0;
}
int getLine(char *s, int lim){
    int c;
    char *p = s;
    while (--lim >0 &&(c=getchar())!= EOF && c!= '\n')
        *p++ =c;
    if (c=='\n'){
        *p++ =c;

    }
    *p = '\0';
    return p-s;
}
void copy(char *to, char *from){
    while ((*to++ = *from++)!='\0')
        ;
}
