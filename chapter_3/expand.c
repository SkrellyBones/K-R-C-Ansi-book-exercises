//function expand(s1,s2) that expands shorthand notations like a-z in s1 into the equivalent complete list abc...xyz in s2.
//a leading or trailing is taken literally.
#include <stdio.h>
void expand(char s1[], char s2[]) {
    int i, j;
    i = j = 0;
    while (s1[i] != '\0') {
        if (s1[i + 1] == '-' && s1[i + 2] != '\0' && 
            ((s1[i] >= 'a' && s1[i] <= 'z' && s1[i + 2] >= 'a' && s1[i + 2] <= 'z' && s1[i] < s1[i + 2]) ||
             (s1[i] >= 'A' && s1[i] <= 'Z' && s1[i + 2] >= 'A' && s1[i + 2] <= 'Z' && s1[i] < s1[i + 2]) ||
             (s1[i] >= '0' && s1[i] <= '9' && s1[i + 2] >= '0' && s1[i + 2] <= '9' && s1[i] < s1[i + 2]))) {
            char start = s1[i];
            char end = s1[i + 2];
            for (char c = start; c <= end; c++) {
                s2[j++] = c;
            }
            i += 3; 
        } else {
            s2[j++] = s1[i++];
        }
    }
    s2[j] = '\0'; //null terminate 
}
int main() {
    char t1[] = "a-b-c";
    char t2[100];
    expand(t1, t2);
    printf("Original: %s\n", t1);
    printf("Expanded: %s\n", t2);
    char t3[]="a-z0-9";
    char t4[100];
    expand(t3,t4);
    printf("Original: %s\n", t3);
    printf("Expanded: %s\n", t4);
    char t5[]="-a-z";
    char t6[100];
    expand(t5,t6);
    printf("Original: %s\n", t5);
    printf("Expanded: %s\n", t6);
    return 0;
}
