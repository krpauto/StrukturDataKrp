#include<stdio.h>
void main(){
int A, *P;
A = 25;
P = &A;
printf("A = %i\n", A);
printf("&A = %X\n", &A);
printf("*P = %i\n", *P);
printf("P = %X", P);
}

