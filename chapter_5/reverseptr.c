#include <string.h>
/*reverseL reverse string s in place*/
void reverse(char *s) {
    char *i = s;
    char *j =s + strlen(s)-1;
    char c;
    while (i < j) {
        c = *i;
        *i++ = *j;
        *j-- = c;
    }
}
