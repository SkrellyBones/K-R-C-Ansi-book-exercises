void any(char s1[], char s2[]){
    int i, j, k, match;
    for(i = 0, j = 0; s1[i] != '\0'; i++){
        match = 0;
        for(k = 0; s2[k] != '\0'; k++){
            if(s1[i] == s2[k]){
                match = 1;
                break;
            }
        }
        if(!match){
            s1[j++] = s1[i];
        }
    }
}
