//function rightrot(x,n) that returns the value of the integer x rotated
//to the right by n positions.
unsigned rightrot(unsigned x, int n){
    int size = sizeof(x) * 8;
    n = n % size; 
    return (x >> n) | (x << (size - n));
}
