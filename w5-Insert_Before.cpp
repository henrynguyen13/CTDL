#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int value;
	struct Node* next;
}Node;

void printList(Node* h){
	Node*p=h;
	while(p!=NULL){
		printf("%d ",p->value);
		p=p->next;
	}
}

Node* makeNode(int v){
	Node* p = (Node*)malloc(sizeof(Node));
	p->value=v;p->next =NULL;
	return p;
}
Node* insertBefore(int v,int u,Node*h){
	if(h==NULL) return NULL;
	if(h->value==u){
		Node*q =makeNode(v);
		q->next=h;
		return q;
	}
	Node*p=h;
	while(p->next!=NULL){
		if(p->next->value==u){
			Node*q=makeNode(v);
			q->next=p->next;
			p->next=q;
			return h;
		}
		p=p->next;
	}
	return h;
}
int main (){
	Node*h=NULL;
	h=makeNode(9);
	for(int i=9;i>=2;i--){
		h=insertBefore(i-1,i,h);
	}
	printList(h);
	printf("\n");
	h=insertBefore(6,3,h);
	printList(h);
	return 0;
}
