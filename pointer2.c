#include <stdio.h>
void main()
{
int A, *P, **PP;
A = 25;
P = &A;
PP = &P;
printf("%i %i %i\n", A, *P, **PP);
printf("%X %X %X\n", &A, &P, &PP);
printf("%X %X %X\n", A, P, PP);
}

