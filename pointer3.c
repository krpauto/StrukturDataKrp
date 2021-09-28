#include <stdio.h>
void main()
{
	int count = 10, *temp, sum = 0,A, *P, **PP;
	A = 25;
	P = &A;
	PP = &P;
	temp = &count;
	*temp = 20;
	temp = &sum;
	*temp = count;
	printf("%i %i %i\n", A, *P, **PP);
	printf("%X %X %X\n", &A, &P, &PP);
	printf("%X %X %X\n", A, P, PP);
	printf("count = %d, *temp = %d, sum = %d\n", count ,*temp,sum);
}
