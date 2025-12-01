// Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to
// use a function for conversion.

#include <stdio.h>
float fahr, celcius;
float lower, upper, step;
float calc(float m);
/* test power function */
int main() {
  lower = 0.0;
  upper = 300.0;
  step = 20.0;
  fahr = lower;

  while (fahr <= upper) {
    float f = calc(fahr);
    printf("%3.0f \t \t %6.1f\n", fahr, f);
    fahr = fahr + step;
  };
}
float calc(float fahr) {
  celcius = (5.0 / 9.0) * (fahr - 32);
  return celcius;
};
