#include <stdio.h>
#include <unistd.h>
#define BOTTLES 99
int main() {
  int i;
  for (i = BOTTLES; i > 0; --i) {
    printf("%d Bottles of beer on the wall, %d Bottles of beer! You take one "
           "down, pass it around, %d Bottles of beer on the wall\n",
           i, i, i - 1);
  }

}
