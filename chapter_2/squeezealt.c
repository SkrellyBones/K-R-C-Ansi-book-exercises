/*an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2.*/

void squeezealt(char s[], char c[]){
    int i, j, k, match;
    for (i = j = 0; s[i] != '\0'; i++) {
        match = 0;
        for (k = 0; c[k] != '\0'; k++) {
            if (s[i] == c[k]) {
                match = 1;
                break;
            }
        }
        if (!match) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}
