/* returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.*/
#include <stdio.h>
void any(char s1[], char s2[]){
    int i, j, k, match;
    for (i = 0; s1[i] != '\0'; i++) {
        match = 0;
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                match = 1;
                break;
            }
        }
        if (match) {
            printf("First occurrence at index: %d\n", i);
            return;
        }
    }
    printf("-1\n");
    
}
