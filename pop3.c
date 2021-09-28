#include <stdio.h>

#define MAX 100
typedef int tipeItem;
typedef struct{
tipeItem data[MAX];
int top;
} Stack;
Stack S;

int main(){
	int i , choose;
	create(&S);
	showmenu:
	showMenu();
	scanf("%d",&choose);
	system("cls");
	if(choose == 1){
		int temp;
		printf("Isi Stack ke %d : ",S.top+2);
		scanf("%d",&temp);
		push(&S,temp);
	}
	else if(choose == 2){
		pop(&S);	
	}
	else if(choose == 3){
		printf("%d\n",getTop(S));
	}
	else if(choose == 4){
		showAll(S);
	}
	else {
		return 0;
	}
//	Choose(choose , S);
	printf("\n\n");
	
	goto showmenu;
	
}
//int Choose (int choose, Stack S){
//	
//}
void showMenu(){
	printf("MENU STACK \n[1] PUSH\n[2] POP\n[3] GETTOP\n[4] TAMPIL SEMUA\n[5] Keluar\n\n");
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

