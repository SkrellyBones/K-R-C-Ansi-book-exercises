/* strlen: return length of string s */
int strLen(char *s) {
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}
