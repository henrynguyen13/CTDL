#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int value;
	struct Node* next; // pointer to the next element
}Node; // tren codeforce bat viet kha nhau

Node* first; // pointer to the first element of the linked list

Node* makeNode(int v){
	Node*p=(Node*)malloc(sizeof(Node));
	p->value=v;p->next=NULL;
	return p;
}
Node* removeNodeRecursive(int v,Node*h){
	// use recursive implementation
	if(h==NULL) return NULL;
	if(h->value==v){
		Node*tmp=h;
		h=h->next;
		free(tmp);
		return h;
	}
	h->next=removeNodeRecursive(v,h->next);
	return h;
}
void printList(Node*h){
	Node*p =h; 
	while(p!=NULL){ 
		printf("%d",p->value);
		p=p->next;
	}
}
Node* addLast(int v,Node*h){
	//create a new node having value =v,insert this node at the end of the list pointed by h
	// return a pointer to the first node of the resulting list
	Node*q=makeNode(v);
	if(h==NULL){
		return q;
	}
	Node*p=h;
	while(p->next!=NULL){
		p=p->next;
		// p points to the last node of the list
	p->next=q;
	return h;
	}
}
Node* remove(int v,Node* h){
	if(h=NULL){
		return NULL;
	}
	if(h->value==v){
		Node* tmp=h;h=h->next;
		free(tmp);return h;
	}
	Node* p=h;
	while(p->next!=NULL){
		if(p->next->value==v) break;
		p=p->next;
	}
	if(p->next!=NULL){
		Node* tmp=p->next;
		p->next=tmp->next;
		free(tmp);
	}
	return h;
}
void freeList(Node*h){
	
}




int main (){
	first = NULL;
	for(int v=1;v<=10;v++){
		first = addLast(v,first);
	}
	printList(first);
	first=remove(1,first);
	printf("After removing, List: ");
	printList(first);
	
	return 0;
}
