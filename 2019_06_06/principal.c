#include <stdio.h>
#include "entero.h"

int main(int argc, char** argv) {
  real a,b;

  a = 5;
  b = 6;
  printf("la suma de %f + %f es %f\n",a,b,suma(a,b));
printf("la resta de %f + %f es %f\n",a,b,resta(a,b));
printf("la multiplicacion de %f + %f es %f\n",a,b,multiplicacion(a,b));
printf("la division de %f + %f es %f\n",a,b,division(a,b));


}

