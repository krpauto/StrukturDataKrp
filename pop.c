#include <stdio.h>

#define MAX 100
typedef int tipeItem;
typedef struct{
tipeItem data[MAX];
int top;
} Stack;
Stack S;

int main(){
	create(&S);
	pop(&S);
	push(&S,4);
	push(&S,5);
	printf("%d\n",getTop(S));
	pop(&S);
	printf("%d\n",getTop(S));
	pop(&S);
	push(&S,10);
}

int create(Stack *S)
{
(*S).top = -1;
}

tipeItem getTop(Stack S){
		return (S.data[S.top]);
}
void pop (Stack *S){
	if(!isEmpty(*S))
	(*S).top--;
	else
	printf("Stack Kosong, Pop Gagal !.\n");
}

void push(Stack *S, tipeItem x)
{
if (!isFull(*S)){
(*S).top++;
(*S).data[(*S).top] = x;
} else
printf("Stack penuh. Push gagal.\n");
}

int isEmpty(Stack S)
{
return (S.top == -1);
}

int isFull(Stack S)
{
return (S.top == MAX-1);
}

