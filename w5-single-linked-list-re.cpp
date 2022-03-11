#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int value;
	struct Node* next; //pointer to the next element
}Node;

Node* first;// pointer to the first element of list

Node* makeNode(int v){ //cap phat bo nho
	Node* p = (Node*)malloc(sizeof(Node));
	p->value=v;p->next=NULL;
	return p;
}
void printList(Node* h){
	Node* p =h; //int i=0;
	while(p!=NULL){//while(i<n){
		printf("%d ",p->value);//printf("%d",a[i])
		p=p->next; //i=i+1;
	}
}

Node* addLast(int v,Node*h){
	//create a new node having value =v, insert this node at the end of list pointed by h
	Node* q =makeNode(v);
	if(h==NULL){
		return q;
	}
	Node* p =h;
	while(p->next!=NULL){
		p=p->next; //p points to the last node of the list
	}
	p->next=q;
	return h;
}

Node* remove(int v,Node* h){
	// remove a first node having value = v in the list pointed by h
	// return the pointer to the first node of the resulting list
	if(h==NULL) return NULL;
	if(h->value==v){
		Node* tmp=h;
		h=h->next;
		free(tmp); //giai phong tmp
		return h;
	}
	Node* p =h;
	while(p->next!=NULL){
		if(p->next->value==v) break; //thoat khoi vong tim kiem
		p=p->next;
	}
	if(p->next!=NULL){
		Node* tmp=p->next;
		p->next=tmp->next;
		free(tmp);
		
	}
	return h;
}

Node* removeR(int v,Node* h){
	// use recursive (de quy)
	if(h==NULL) return NULL;
	if(h->value==v){
		Node* tmp=h;
		h=h->next;
		free(tmp);
		return h;
	}
	h->next=removeR(v,h->next);
	return h;
}
Node* insertFirst(int v,Node* h){
	Node* p =makeNode(v);
	p->next=h;
	return p;
	
}

Node* insertBefore(int v,int u,Node*h){
	if(h==NULL) return NULL;
	if(h->value==u){
		Node* q= makeNode(v);
		q->next=h;
		return q;
	}
	Node* p =h;
	while(p->next!=NULL){
		if(p->next->value==u){
			Node* q=makeNode(v);
			q->next=p->next;
			p->next=q;
			return h;
		}
		p=p->next;
	}
	return h;	
}
Node* insertBeforeR(int v,int u,Node*h){
	//them 1 node co gia tri v vao truoc node co gia tri u tren DS duoc tro boi h
	if(h==NULL) return NULL;
	if(h->value==u){ //chen phan tu moi vao dau danh sach
		Node* p =makeNode(v);
		p->next = h;
		return p;
	}
	h->next=insertBeforeR(v,u,h->next);
	return h;
}
Node* insertAfter(int v,int u,Node*h ){
	// them 1 node co gia tri v vao  sau node co gia tri u tren DS duoc tro boi h
	// tra ve con tro den dau danh sach ket qua
	if(h==NULL) return NULL;
	if(h->value==u){
		Node* p=makeNode(v);
		p->next=h->next;
		h->next=p;
		return h;
	}
	h->next=insertAfter(v,u,h->next);
	return h;
	
}

Node* reverse(Node*h){
	//dao nguoc danh sach, tra ve con tro den danh sach ket qua
	Node* pp =NULL;// previous(phan tu truoc p)
	Node* p=h; //current
	Node* np = NULL; // keep track the next node of p
	while(p!=NULL){
		np=p->next;
		p->next=pp;
		pp=p;
		p=np;
	}
	return pp;
}
void freeList(Node* h){
	if(h==NULL) return;
	freeList(h->next); //giai phong vung nho cho danh sach con
	free(h);// giai phong vung nho duoc tro boi h
}
int main (){
	first = NULL;
	for(int v=1;v<=10;v++){
		first=insertFirst(v,first);
	}
	printList(first);
	first=removeR(7,first);
	printf("\nAfter removing by recursive: ");
	printList(first);
	first=remove(7,first);
	printf("\nAfter remove: ");
	printList(first);
	first=reverse(first);
	printf("\nAfter reversing:",first);
	printList(first);
	first=insertBefore(11,3,first); //chen 11 vao truoc 3
	printf("\nAfter inserting:",first);
	printList(first);
	first=insertAfter(11,11,first);
	printf("\nAfter inserting:",first);
	printList(first);
	
	return 0;
}
