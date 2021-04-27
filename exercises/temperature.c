#include <stdio.h>
/* print Fahrenheit-Celsius table
  floating-point version */

#define LOWER 0
#define UPPER 300
#define STEP 20

double fToC(double *fahr);
void printLine(double *fahr);
  
double fToC(double *fahr)
{
  return (5.0/9.0) * (*fahr-32.0);
}

void printLine(double *fahr)
{
    printf("%3.0f %6.1f\n", *fahr, fToC(fahr));
}

int main()
{
  double fahr = LOWER;
  
  printf(" F  |  C\n");
  
  while (fahr <= UPPER) {
    printLine(&fahr);
    fahr += STEP;
  }

  printf("\n F  |  C\n");
  
  for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
    printLine(&fahr);
}

