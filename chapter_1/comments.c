// program to remove all comments from a C program
#include <stdio.h>
int main() {
  int c;
  int d;
  while ((c = getchar()) != EOF) {
    if (c == '/') {
      d = getchar();
      if (d == '*') {
        int prev = 0;
        int curr = 0;

        prev = getchar();
        curr = getchar();
        while (prev != '*' || curr != '/') {
          if (curr == EOF)
            break;
          prev = curr;
          curr = getchar();
        }

        // Done skipping comment, continue loop
        continue;
      } else {
        putchar(c);
        if (d != EOF)
          putchar(d);
      }
    }
      putchar(c);  
  }
}
