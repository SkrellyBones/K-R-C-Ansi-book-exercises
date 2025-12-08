/* strlen: return length of string s */
int strLen(char *s) {
    char *p = s;
    while (*p != '\0')
        p++;
    return p - s;
}
