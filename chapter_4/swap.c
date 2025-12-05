// macro swap(t,x,y) that interchanges two arguments of type t.
#include <stdio.h>
#define swap(t, x, y)                                                          \
    do {                                                                       \
        t _temp = x;                                                           \
        x = y;                                                                 \
        y = _temp;                                                             \
                                                                               \
    } while (0)
int main(){
    int a = 1;
    int b = 2;
    printf("before swap: %d %d\n",a,b);
    swap(int,a,b);
    printf("after swap: %d %d\n",a,b);

}
