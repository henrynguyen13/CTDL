#include<iostream>
#include<math.h>
using namespace std;

struct Node{
	int id;
	Node* leftChild;
	Node* rightChild;
};
Node* root = NULL;

Node* insert(Node*r, int v){
	//add element with value = v to the binary tree
	if(r==NULL){
		Node* tmp = new Node;
		tmp->id =v;
		tmp->leftChild = NULL;
		tmp->rightChild = NULL;
		return tmp;
	} else {
		if(v < r->id){
			r->leftChild = insert(r->leftChild,v);
		} else {
			r->rightChild = insert(r->rightChild,v);
		}
	}
}

void inOrder(Node*r){
	if(r==NULL) return;
	inOrder(r->leftChild);
	cout << r->id << " ";
	inOrder(r->rightChild);
}

void preOrder(Node*r){
	if(r==NULL) return;
	cout << r->id << " ";
	preOrder(r->leftChild);
	preOrder(r->rightChild);
}

void postOrder(Node*r){
	if(r==NULL) return;
	postOrder(r->leftChild);
	postOrder(r->rightChild);
	cout << r->id << " ";
}

void printListPre(Node*r) {
	if(r!=NULL){
		cout << r->id << " ";
		printListPre(r->leftChild);
		printListPre(r->rightChild);
	}
}

void printListIn(Node*r) {
	if(r!=NULL){
		printListIn(r->leftChild);
		cout << r->id << " ";
		printListIn(r->rightChild);
	}
}


int countLeaves(Node*r){
	//count leaves of Binary Tree
	if(r==NULL) return 0;
	if(r->leftChild==NULL && r->rightChild==NULL) return 1;
	else {
		return countLeaves(r->leftChild) +countLeaves(r->rightChild);
	}
}

int treeLevel(Node*r){
	// tra ve bac cua cay
	if(r==NULL) return -1;
	if(r->leftChild==NULL && r->rightChild==NULL) return 0;
	else {
		return 1+max(treeLevel(r->leftChild),treeLevel(r->rightChild));
	}
}

bool checkAvl(Node*r){
	//check AVL Binary Tree
	if(r==NULL) return true;
	if(abs(treeLevel(r->rightChild)-treeLevel(r->leftChild)) >1) return false;
	return checkAvl(r->leftChild) && checkAvl(r->rightChild);
}
Node* turnLeft(Node* a){
	//Left rotation technique
	//Ve ra la hieu nhe =)))
	Node* b = a->rightChild;
	Node* c = b->leftChild;
	a->rightChild = c;
	b->leftChild = a;	
	return b;
}

Node* turnRight(Node* a){
	//Right rotation technique.
	Node* b = a->leftChild;
	Node* c = b->rightChild;
	a->leftChild = c;
	b->rightChild = a;
	return b;
}

Node* updateTreeAvl(Node* r){
	// turns the binary search tree into an AVL tree.
	if(abs(treeLevel(r->rightChild)-treeLevel(r->leftChild)) >1){
		if(treeLevel(r->leftChild) > treeLevel(r->rightChild)) {
			Node* p =r->leftChild;
			if(treeLevel(p->leftChild) >= treeLevel(p->rightChild)){
				r=turnRight(r);
			} else {
				r->leftChild = turnLeft(r->leftChild);
				r = turnRight(r);
			}
		} else {
			Node* p =r->rightChild;
			if(treeLevel(p->leftChild) >= treeLevel(p->rightChild)){
				r->rightChild = turnRight(r->rightChild);
				r = turnLeft(r);
			} else {
				r = turnLeft(r);
			}
		}
	}
	if(r->leftChild!=NULL) r->leftChild = updateTreeAvl(r->leftChild);
	if(r->rightChild!=NULL) r->rightChild = updateTreeAvl(r->rightChild);
	return r;
}

int count(Node*r,int v){
	//count the number of elements with value = x in the tree
	if(r==NULL) return 0;
	if(r->id==v) return 1 + count(r->leftChild,v) + count(r->rightChild,v);
	else if (r->id > v ){
		return count(r->leftChild,v);
	} else {
		return count(r->rightChild,v);
	}
}

Node* deleteNode(Node*r,int v){
	if(r==NULL) return NULL;
	if(r->id==v) return NULL;
	else if(r->id <v ){
		r->rightChild=deleteNode(r->rightChild,v);
	} else {
		r->leftChild = deleteNode(r->leftChild,v);
	}
	return r;
}
int main () {
	int n,x;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x;
		root = insert(root,x);
	}
//	inOrder(root);
//	cout << countLeaves(root);
//	cout << treeLevel(root);
	
//	cout << boolalpha; // in ra true, false thay the 1,0
//	cout << checkAvl(root);
	
	
	//begin: in ra bac cua cay sau khi bien BST thanh AVL
//	while(!checkAvl(root)) {
//		root=updateTreeAvl(root);
//	}
//	cout << treeLevel(root);
	//end
	
//	int v;
//	cin >> v;
//	cout << count(root,v);

	int k;
	cin >> k;
	root=deleteNode(root,k);
	if(root ==NULL) {
		cout << "NULL";
	} else {
		printListIn(root);
	}
	
	return 0;
}
