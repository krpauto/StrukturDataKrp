#include <stdio.h>

#define MAX 100
typedef int tipeItem;
typedef struct{
tipeItem data[MAX];
int top;
} Stack;
Stack S;

int main(){
	int i;
	create(&S);
	pop(&S);
	for(i = 0; i<5 ; i++){
		int temp;
		printf("Isi Stack ke %d : ",i+1);
		scanf("%d",&temp);
		push(&S,temp);
	}
	showAll(S);	
}

void showAll (Stack S){
	int i;
	for (i = 0 ; i<=S.top ; i++){
		printf("%d\n",S.data[i]);
	}
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

