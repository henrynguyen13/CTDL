#include<stdio.h>
#define N 100001
#include<stdlib.h>
typedef struct Node{
	int id;
	struct Node*next; 
}Node;

typedef struct QNode{ //queue
	int id;
	struct QNode*next;
}QNode;

int n,m;
Node* A[N];
int d[N];
QNode*head,*tail;// phan tu dau va cuoi cua queue

void initQueue(){
	head=NULL;tail=NULL;
}
int Qempty(){
	return head==NULL && tail ==NULL;
}

Node* makeNode(int v){
	Node*p=(Node*)malloc(sizeof(Node));
	p->id=v;
	p->next=NULL;
	return p;
}

QNode* makeQNode(int v){
	QNode*p=(QNode*)malloc(sizeof(QNode));
	p->id=v;p->next=NULL;
	return p;
}
QNode* pop(){
	if(Qempty()) return NULL;
	QNode*rs=head;
	head=head->next;
	if(head==NULL) tail=NULL; // bao hieu hang doi rong
	return rs;
	
}

void push(int v){
	QNode*p=makeQNode(v);
	if(Qempty()){ //queue ban dau rong
		head=p;tail=p;return;
	}
	tail->next=p;tail=p;
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

int BFS(int u){
	d[u]=0;// dinh u da duoc tham
	initQueue();
	push(u);
	while(!Qempty()){
		QNode* p =pop();
		int v=p->id;
		for(Node*q=A[v];q!=NULL;q=q->next){
			int x=q->id;
			if(d[x]>-1){ // x has been visited
				if((d[v]+d[x])%2==0) return 0;
			} else {
				d[x]=d[v]+1;
				push(x);
			}
		}
	} 
	return 1;
}
void solve(){
	for(int v=1;v<=n;v++) d[v]=-1;//chua dinh nao duoc duyet
	int ans=1;
	for(int v=1;v<=n;v++){
		if(d[v]==-1){ // v has not been visited
			int ok = BFS(v);
			if(ok==0){
				ans=0;
				break;
			}
		}
	}
	printf("%d",ans);

}
int main (){
	input();
	solve();
	return 0;
}
