/* strlen: return length of s */
int strLen(char s[]) {
    int i;
    while (s[i] != '\0')
        ++i;
    return i;
}
//this is the K&R version of the strlen function.
