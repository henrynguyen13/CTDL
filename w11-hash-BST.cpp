#include<stdio.h>
#define N 200000
#include<string.h>
#define M 100000
#include<stdlib.h>
typedef struct Node{
	char key[50];
	struct Node* leftChild;
	struct Node* rightChild;
}Node;

Node*T[M];// T[i] is the pointer to the root of the corresponding

Node* makeNode(char*k){
	Node*p=(Node*)malloc(sizeof(Node));
	strcpy(p->key,k);
	p->leftChild=NULL;
	p->rightChild=NULL;
	return p;
}
Node* insertBST(char*k,Node*r){
	if(r==NULL) return makeNode(k);
	int c=strcmp(r->key,k);
	if(c<0) r->rightChild =insertBST(k,r->rightChild);
	else if (c>0) r->leftChild = insertBST(k,r->leftChild);
	return r;	
	
}


Node* findBST(char* k,Node*r){
	if(r==NULL) return NULL;
	int c=strcmp(r->key,k);
	if(c==0) return r;
	if(c<0) return findBST(k,r->rightChild);
	return findBST(k,r->leftChild);
	
}
int h(char*s){
	int m = strlen(s);
	int ans=0;
	for(int i=0;i<m;i++){
		ans=ans*256+s[i];
		ans=ans % M;
	}
	return ans;
}
int find(char*k){
	int index = h(k);
	Node*p=findBST(k,T[index]);
	if(p==NULL) return 0;
	return 1;
}
int insert(char*k){
	int ok=find(k);
	if(ok==1) return 0;
	int index=h(k);
	T[index]=insertBST(k,T[index]);
	return 1;
}

int main (){
	char cmd[60];
	while(1){
		scanf("%s",cmd);
		if(strcmp(cmd,"*")==0) break;
		insert(cmd);
	}
	char k[60];
	while(1){
		scanf("%s",cmd);
		if(strcmp(cmd,"***")==0) break;
		if(strcmp(cmd,"$insert")==0){
			scanf("%s",k);
			int rs=insert(k);
			printf("%d\n",rs);
		} else if (strcmp(cmd,"$find")==0){
			scanf("%s",k);
			int rs=find(k);
			printf("%d\n",rs);
		}
	}
	return 0;
} 
