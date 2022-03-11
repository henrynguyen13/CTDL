#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
	int key;
	struct Node* leftChild;
	struct Node* rightChild;
}Node;
Node* root =NULL;

Node* makeNode(int v){
	Node*p=(Node*)malloc(sizeof(Node));
	p->key=v;
	p->leftChild=NULL;p->rightChild=NULL;
	return p;
}

Node* insert(Node* r,int v){
	if(r==NULL) r=makeNode(v);
	else if(r->key >v){
		r->leftChild=insert(r->leftChild,v);
	} else if(r->key <=v){
		r->rightChild=insert(r->rightChild,v);
	} 
	return r;
}
Node* find(Node* r,int v){
	if(r==NULL) return NULL;
	if(v==r->key) return r;
	else if(v<r->key) {
		return find(r->leftChild,v);
	}
	else {
		return find(r->rightChild,v);
	}
}
Node* findMin(Node*r){
	if(r==NULL) return NULL;
	Node* lmin = findMin(r->leftChild);
	if(lmin!=NULL) return lmin;
	return r;
}
Node* removeK(Node*r,int v){
	if(r==NULL) return NULL;
	else if(r->key >v) r->leftChild = removeK(r->leftChild,v);
	else if(r->key <v) r->rightChild = removeK(r->rightChild,v);
	else {
		if(r->leftChild !=NULL && r->rightChild !=NULL){
			Node* tmp = findMin(r->rightChild);
			r->key = tmp->key;
			r->rightChild = removeK(r->rightChild,tmp->key);
		} else {
			Node* tmp = r;
			if(r->leftChild == NULL) r=r->rightChild;
			else r=r->leftChild;
			free(tmp);
		}
	}
	return r;
}
int isFindable(Node*r,int key){
	Node*p=find(r,key);
	if(p==NULL) return 0;
	else return 1;
}
	


int main (){
	while(1){
		int key;
		scanf("%d",&key);
		if(key==-1){
			break;
		} 
		if(find(root,key)==NULL){
			root=insert(root,key);
		}
	}
	char cmd[50];
	while(1){
		scanf("%s",cmd);
		if(strcmp(cmd,"$insert")==0){
			int key;
			scanf("%d",&key);
			if(find(root,key)==NULL){
				printf("1\n");
				root=insert(root,key);
			} else {
				printf("0\n");
			}
		} 
		if(strcmp(cmd,"$remove")==0){
			int key;
			scanf("%d",&key);
			if(find(root,key)!=NULL){
				printf("1\n");
				root=removeK(root,key);
			} else {
				printf("0\n");
			}
		} 
		if(strcmp(cmd,"$find")==0){
			int key;
			scanf("%d",&key);
			printf("%d\n",isFindable(root,key));	
		}
		if(strcmp(cmd,"*") == 0) break;
	}
	return 0;
}
