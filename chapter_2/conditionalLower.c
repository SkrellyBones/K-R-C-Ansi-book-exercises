
/*lower: conver c to lower case: ASCII only, using conditional expression*/
int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c; 
}
