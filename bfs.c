#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 8

struct Simpul {
   char label;
   bool visited;
};

struct Simpul* lstVertices[MAX];

//queue variables

int queue[MAX];
int rear = -1;
int front = 0;
int queueItemCount = 0;

//adjacency matrix
int adjMatrix[MAX][MAX];

//Simpul count
int SimpulCount = 0;

//queue functions

void insert(int data) {
   queue[++rear] = data;
   queueItemCount++;
}

int removeData() {
   queueItemCount--;
   return queue[front++]; 
}

bool isQueueEmpty() {
   return queueItemCount == 0;
}

//tambah Simpul to the Simpul list
void tambahSimpul(char label) {
   struct Simpul* Simpul = (struct Simpul*) malloc(sizeof(struct Simpul));
   Simpul->label = label;  
   Simpul->visited = false;     
   lstVertices[SimpulCount++] = Simpul;
}

//tambah Busur to Busur array
void tambahBusur(int start,int end) {
   adjMatrix[start][end] = 1;
   adjMatrix[end][start] = 1;
}

//display the Simpul
void displaySimpul(int SimpulIndex) {
   printf("%c ",lstVertices[SimpulIndex]->label);
}

//get the adjacent unvisited Simpul
int getAdjUnvisitedSimpul(int SimpulIndex) {
   int i;
	
   for(i = 0; i<SimpulCount; i++) {
      if(adjMatrix[SimpulIndex][i] == 1 && lstVertices[i]->visited == false)
         return i;
   }
	
   return -1;
}

void breadthFirstSearch() {
   int i;

   //mark first node as visited
   lstVertices[0]->visited = true;

   //display the Simpul
   displaySimpul(0);   

   //insert Simpul index in queue
   insert(0);
   int unvisitedSimpul;

   while(!isQueueEmpty()) {
      //get the unvisited Simpul of Simpul which is at front of the queue
      int tempSimpul = removeData();   

      //no adjacent Simpul found
      while((unvisitedSimpul = getAdjUnvisitedSimpul(tempSimpul)) != -1) {    
         lstVertices[unvisitedSimpul]->visited = true;
         displaySimpul(unvisitedSimpul);
         insert(unvisitedSimpul);               
      }
		
   }   

   //queue is empty, search is complete, reset the visited flag        
   for(i = 0;i<SimpulCount;i++) {
      lstVertices[i]->visited = false;
   }    
}

int main() {
   int i, j;

   for(i = 0; i<MAX; i++){// set adjacency 
      for(j = 0; j<MAX; j++) // matrix to 0
         adjMatrix[i][j] = 0;
   }

   tambahSimpul('A');   // 0
   tambahSimpul('B');   // 1
   tambahSimpul('C');   // 2
   tambahSimpul('D');   // 3
   tambahSimpul('E');	 // 4
   tambahSimpul('F');   // 5
   tambahSimpul('G');   // 6
   tambahSimpul('H');   // 7
 
   tambahBusur(0, 1);    // A - B
   tambahBusur(0, 2);    // A - C
   tambahBusur(1, 3);    // B - D
   tambahBusur(1, 4);    // B - E
   tambahBusur(2, 5);    // C - F
   tambahBusur(2, 6);    // C - G
   tambahBusur(3, 7);    // D - H
   tambahBusur(4, 7);    // E - H
   tambahBusur(5, 7);    // F - H
   tambahBusur(6, 7);    // G - H
   
   printf("Graf terdiri dari simpul : \n");
   for(i=0 ; i<MAX ; i++){
   	displaySimpul(i);
   }
   
   printf("\n===================================\n");
   printf("\nBreadth First Search: \n");
   
   breadthFirstSearch();

   return 0;
 	  
}
