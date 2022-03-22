#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    int id;
    struct Node* leftMostChild;// con tro den con trai nhat
    struct Node* rightSibling;// con tro den anh em ben phai
}Node;

Node* root;

Node* makeNode(int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = v; p->leftMostChild = NULL; p->rightSibling = NULL;
    return p;
}

Node* find(int v, Node* r){
    // tra ve con tro den nut co id bang v tren cay goc r
    if(r == NULL) return NULL;
    if(r->id == v)  return r;
    Node* p = r->leftMostChild;
    while(p != NULL){
        Node* q = find(v, p);
        if(q != NULL) return q;
        p = p->rightSibling;
    }
    return NULL;
}
void insert(int u, int v){
    // tao mot nut co id bang u, chen vao cuoi DS nut con cua nut co id bang v
    // tren cay goc la root
    Node* r = find(v, root);
    Node* p = NULL;
    //Node* p = find(u, root);
    //if(p != NULL) return;
    p = makeNode(u);
    if(r->leftMostChild == NULL)
        r->leftMostChild = p;
    else{
        Node* h = r->leftMostChild;
        while(h->rightSibling != NULL)
            h = h->rightSibling;
        	h->rightSibling = p;
    }
}
void printTree(Node* r){
    if(r == NULL) return;
    printf("%d: ",r->id);
    for(Node* p = r->leftMostChild; p != NULL; p = p->rightSibling){
        printf("%d ",p->id);
    }

    printf("\n");
    for(Node* p = r->leftMostChild; p != NULL; p = p->rightSibling){
        printTree(p);
    }
}
void inOrder(Node* r){
    // TODO
    if(r == NULL) return ;
    Node* p = r->leftMostChild;// p tro vao nut goc cay con r1
    inOrder(p);
    printf("%d ",r->id);// tham nut goc
    if(p == NULL) return;
    p = p->rightSibling;// truy cap den goc r2
    while(p != NULL){
        inOrder(p);// tham cay theo thu tu giua
        p = p->rightSibling;
    }
}
void preOrder(Node* r){
    // TODO
    if(r == NULL) return;
    printf("%d ",r->id);
    Node* p = r->leftMostChild;
    while(p != NULL){
        preOrder(p);
        p = p->rightSibling;
    }

}
void postOrder(Node* r){
    // TODO
    if(r == NULL) return;
    Node* p = r->leftMostChild;
    while(p != NULL){
        postOrder(p);
        p = p->rightSibling;
    }
    printf("%d ",r->id);
}

int count(Node* r){
	// return the number of nodes of the tree rooted at r
	if(r==NULL) return 0;
	int ans = 1;// nut goc
	Node* p = r->leftMostChild;
	while (p!=NULL){
		ans+=count(p);
		p=p->rightSibling;
	}
	return ans;
}
int countLeaves(Node* r){
	//return the number of lead nodes of the tree rooted at r
	if(r==NULL) return 0;
	int ans=0;
	Node*p=r->leftMostChild;
	if(p==NULL) ans=1;
	while(p!=NULL){
		ans+=countLeaves(p);
		p = p->rightSibling;
	}
	return ans;
}
int heightNode(Node*r){
	if(r==NULL) return 0;
	int maxH=0;
	for(Node* p =r->leftMostChild;p!=NULL;p=p->rightSibling){
		int h = heightNode(p);
		if(h>maxH) maxH = h;
	}
	return maxH+1;
}
int height(int v){
	//return the height of the node having id =v
	Node* r = find(v,root);
	return heightNode(r);
}

int depthNode(int v,Node*r,int d){
	// d la do sau cua r tren cay goc root
	if(r==NULL) return -1; // v khong ton tai tren cay goc r
	if(r->id == v) return d;
	for(Node*p=r->leftMostChild;p!=NULL;p=p->rightSibling){
		if(p->id==v) return d+1;
		int rs = depthNode(v,p,d+1);
		if(rs>-1) return rs;
	}
	return -1;
	
}
int depth(int v){
	return depthNode(v,root,1);
}

int main(){
    freopen("tree.txt","r",stdin);

    char cmd[50];
    while(1){
        scanf("%s",cmd);
        if(strcmp(cmd,"$MakeRoot") == 0){
            int  v; scanf("%d",&v);
            root = makeNode(v);
            //printf("make root %d\n",v);
        }else if(strcmp(cmd,"$Insert")==0){
            int u,v; scanf("%d %d",&u,&v);
            insert(u,v);
        }else if(strcmp(cmd,"$InOrder") == 0){
            inOrder(root);
            printf("\n");
        }else if(strcmp(cmd,"$PreOrder") == 0){
            preOrder(root);
            printf("\n");
        }else if(strcmp(cmd,"$PostOrder") == 0){
            postOrder(root);
            printf("\n");
        }else if(strcmp(cmd,"*") == 0) break;
    }
    //printTree(root);
    printf("number of leaf nodes = %d\n",countLeaves(root));
    printf("number of nodes = %d\n",count(root));
    printf("height %d\n",height(10));
    printf("depth %d\n",depth(4));
	return 0;
}

