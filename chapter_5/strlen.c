/* strlen: return length of string s */
#include <stdio.h>
int strLen(char *s) {
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}
int main(){
    char *s = "Hello World";
    int a = strLen(s);
    printf("String: %s\n", s);
    printf("Length of string: %d\n", a);

}
