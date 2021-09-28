#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef char tipeItem;
typedef struct{
	tipeItem data[MAX];
	int top;
}Stack;
Stack S;

void create(Stack *S){
	(*S).top = -1;
}

int isFull(Stack S){
	return (S.top == MAX-1);
}

int isEmpty(Stack S){
	return (S.top == -1);
}

void push(Stack *S, tipeItem x){
	if (!isFull(*S)){
		(*S).top++;
		(*S).data[(*S).top] = x;
	} else {
		printf("Stack Penuh! Push gagal.\n");
	}
}

void pop (Stack *S){
	if (!isEmpty(*S)){
		(*S).top--;
	} else {
		printf("SALAH.\n");
		exit(0);
	}
}

void cari(){
	if (S.top == -1){
		printf("BENAR\n");
	} else {
		printf("SALAH\n");
	}
}

void main(){
	int i;
	create(&S);
	char x[20];
	printf("Masukkan operasi aritmatika : ");
	scanf("%s", &x);
	for (i=0 ; x[i]!='\0' ; i++){
		if(x[i] == '('){
			push(&S, x[i]);
		} else if (x[i] == ')') {
			pop(&S);
		}
	}
	cari();
}
