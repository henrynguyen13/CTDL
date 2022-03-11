#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[1000000];
typedef struct Node{
	char c; // bieu dien dau ngoac
	struct Node* next;
}Node;

Node* top = NULL;// con tro den dinh cua stack

Node* makeNode(char c){
	Node*p =(Node*)malloc(sizeof(Node));
	p->c=c;
	p->next=NULL;
	return p;
}
void push(char c){ //them phan tu 
	//TODO
	Node* p = makeNode(c);
	p->next=top;
	top=p;
}
char pop(){ // lay 1 phan tu khoi stack, tra ve truong c
	//TODO
	char c=top->c;
	Node*tmp=top;
	top=top->next;
	free(tmp);//thu hoi bo nho
	return c;
}
int empty(){
	// tra ve 1 neu stack rong, va tra ve 0 neu nguoc lai
	return top==NULL;
}
int match(char o,char c){
	if(o=='(' && c==')') return 1;
	if(o=='[' && c==']') return 1;
	if(o=='{' && c=='}') return 1;
	return 0;
}
int check(char*s){
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
			push(s[i]);
		 }else{ //s[i] la ngoac dong
		 	if(empty()==1) return 0;
		 	char o=pop(); // lay ra ngoac mo tu stack 
		 	if(match(o,s[i])==0) return 0;
		 }
	}
return empty();
}

int main (){
	scanf("%s",s);
	int ans=check(s);
	printf("%d",ans);
	return 0;
}
