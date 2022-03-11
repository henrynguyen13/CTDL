#include<stdio.h>
#define N 100001
#include<stdlib.h>
typedef struct Node{
	int id;
	struct Node*next; 
}Node;

int n,m;
Node* A[N];
int visited[N];
int nbCC;
Node* makeNode(int v){
	Node*p=(Node*)malloc(sizeof(Node));
	p->id=v;
	p->next=NULL;
	return p;
}

Node* add(int v,Node*r){ //add a new element to the list headed by pointer
	Node*p=makeNode(v);
	p->next=r;
	return p;
}

void input(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		A[v]=add(u,A[v]);//add u to the adjacent list of v
		A[u]=add(v,A[u]);
	}
}
void printGraph(){
	for(int v=1;v<=n;v++){
		//print the linked list headed by A[v]
		printf("A[%d]:",v);
		for(Node*p=A[v];p!=NULL;p=p->next){
			printf("%d ",p->id);
		}
		printf("\n");
	}
}

void DFS(int s){
	visited[s]=1;
	//iterate over element of A[u]
	Node*p=A[s]; //A[s] la con tro dau cua p
	while(p!=NULL){
		int v=p->id;
		if(!visited[v]){
			DFS(v);
		}
		p=p->next;
	}
}
void solve(){
	//initialization
	for(int v=1;v<=n;v++) visited[v]=0;
	nbCC=0;
	for(int v=1;v<=n;v++){
		if(!visited[v]){
			nbCC+=1;
			DFS(v);
		}
	}
	printf("%d",nbCC);
}
int main (){
	input();
//	printGraph();
	solve();
	return 0;
}
