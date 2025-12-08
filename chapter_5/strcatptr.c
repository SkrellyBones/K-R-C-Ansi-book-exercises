/*strcat: concatenate t to end of s; s must be big enough, pointer version*/
void Strcat(char *s, char *t){
    while (*s != '\0')
        s++;
    while((*s++ = *t++)!='\0')
       ; 
}
