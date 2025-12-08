/*strend(s,t), which returns 1 if the string t occurs at the
end of the string s, and zero otherwise.*/
int strend(char *s, char *t) {
    char *s_end = s;
    char *t_end = t;

    while (*s_end)
        s_end++; //go to the end of s

    while (*t_end)
        t_end++; //go to the end of t

    while (t_end >= t) {
        if (*s_end != *t_end)
            return 0;      //mismatch
        s_end--; //walk it back
        t_end--;
    }

    return 1;  //match 
}
