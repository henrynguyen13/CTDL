#include<iostream>
using namespace std;

int n;
struct Node {
	int value;
	Node* next;
};

Node* makeNode(int v){
	Node*p = new Node;
	p->value=v;p->next=NULL;
	return p;
}

void printList(Node*h){
	Node*p=h;
	while(p!=NULL){
		cout << p->value << " ";
		p=p->next;
	}
	cout<< endl;
}

Node* addElement(Node* h, int v){
	//Thêm một phần tử vào cuối listLinker khi biết con trỏ đang trỏ vào phần tử cuối
	Node*p =makeNode(v);
	h->next=p;
	return p;
}

Node* addLast(Node*h,int v){
	// create a new node having value v, insert this node at the end of list pointed by h
	// return a pointer to the first node of the resulting list
	Node*q= makeNode(v);
	if(h==NULL) return q;
	Node*p = h;
	while(p->next!=NULL){
		p=p->next;
	}
	//At this time, p points to the last node of the list
	p->next=q;
	return h;
}
Node* addHead(Node*h,int v){
	Node* p = new Node;
	p->value=v;
	p->next=h;
	return p;
}

Node* addTail(Node*h,int v){
	Node*q=h;
	while(q->next!=NULL){
		q=q->next;
	}
	Node*p = new Node;
	p->value =v;
	p->next=NULL;
	q->next=p;
	return h;
}

Node* addAt(Node*h, int v, int k){
	Node*p=h;
	for(int i=0;i<k-1;i++){
		p=p->next;
	}
	Node* q =new Node;
	q->value =v;
	q->next=p->next;
	p->next=q;
	return h;
}

Node* remove(Node*h, int v){
	//remove a first node having value = v in the list pointed by h
	// return the pointer to the first node of the resulting list
	if(h==NULL) return NULL;
	if(h->value==v){
		Node*tmp= h;
		h=h->next;
		delete(tmp);
		return h;
	}
	Node*p=h;
	//Lúc này, h !=NULL => p!=NULL => Ta chỉ cần xét p->next
	while(p->next!=NULL){
		if(p->next->value==v){
			Node*tmp = p->next;
			p->next=p->next->next;
			delete(tmp);
			return h;
		}
		p=p->next;
	}
	return h;
}

Node* removeRecursive(Node*h,int v){
	//Using recursive
	if(h==NULL) return NULL;
	if(h->value==v){
		Node*tmp=h;
		h=h->next;
		delete(tmp);
		return h;
	}
	h->next=removeRecursive(h->next,v);
	return h;
}

//Begin: remove phần tử ở chỉ số k
Node* removeHead(Node*h){
	Node*p = h;
	h=h->next;
	delete(p);
	return h;
}
Node* removeTail(Node*h){
	Node*p =h;
	while(p->next->next!=NULL){
		p=p->next;
	}
	delete(p->next);
	p->next=NULL;
	return h;
}
Node* removeAt(Node*h,int k){
	Node*p = h;
	for(int i=0;i<k-1;i++){
		p=p->next;
	}
	Node*tmp = p->next;
	p->next=p->next->next;
	delete(tmp);
	return h;
}
//End: remove phần tử ở chỉ số k


Node* insertBefore(Node*h,int v,int u){
	//them mot node co gia tri v vao truoc node dau tien co gia tri u tren ds duoc tro boi h
	// tra ve con tro den dau danh sach ket qua
	if(h==NULL) return NULL;
	if(h->value==u){
		Node*q = makeNode(v);
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

Node* insertBeforeR(Node*h, int v,int u){
	// Using recursive 
	if(h==NULL) return NULL;
	if(h->value==u) {
		Node*q = makeNode(v);
		q->next=h;
		return q;
	}
	h->next= insertBeforeR(h->next,v,u);
	return h;
} 

Node* insertAfter(Node*h,int v,int u) {
	//them mot node co gia tri v vao sau node dau tien co gia tri u tren ds duoc tro boi h
	// tra ve con tro den dau danh sach ket qua
	if(h==NULL) return NULL;
	if(h->value==u) {
		Node*q=makeNode(v);
		h->next=q;
		q->next=h->next;
		return h;
	}
	Node*p=h;
	while(p->next!=NULL){
		if(p->next->value==u){
			Node*q=makeNode(v);
			q->next=p->next->next;
			p->next->next=q;
			return h;	
		}
		p=p->next;
	}
	return h;
}

Node* insertAfterR(Node*h,int v,int u){
	if(h==NULL) return NULL;
	if(h->value==u) {
		Node*q=makeNode(v);
		q->next=h->next;
		h->next=q;
		return h;
	}
	h->next= insertAfterR(h->next,v,u);
	return h;
}

Node* reverse(Node*h){
	Node*p=h;
	Node*pp=NULL;
	Node*np=NULL;
	while(p!=NULL){
		np=p->next;
		p->next=pp;
		pp=p;
		p=np;
	}
	return pp;
}

int sum(Node*h){
	//Tong gia tri cac phan tu cua mot ds lien ket duoc tro boi h
	Node*p=h;
	int S=0;
	while(p!=NULL){
		S+=p->value;
		p=p->next;
	}
	return S;
}

int sumRecursive(Node*h){
	// using recursive
	if(h==NULL) return 0;
	return h->value + sumRecursive(h->next);
}

Node* getNode(Node*h,int k){
	//point to value at chi so k
	Node*p=h;
	for(int i=0;i<k;i++){
		p=p->next;
	}
	return p;
} 

Node* deleteBigger(Node*h, int k){
	//xoa nhung phan tu co gia tri lon hon gia tri phan tu o chi so k
	Node*p = h;
	Node* ans= new Node;
	while(p!=NULL){
		if(p->value <=k){
			ans = makeNode(p->value);
			p=p->next;
			break;
		}
		p=p->next;
	}
	while (p != NULL){
		if (p->value <= k){
			ans = addTail(ans, p->value);
		}
		p = p->next;
	}
	return ans;
}
Node* changeNode(Node*h,int a,int b){
	//changes all nodes having value = a into value = b pointed by h
	Node*p=h;
	while(p!=NULL){
		if(p->value==a){
			p->value=b;
		}
		p=p->next;
	}
	return h;
}


int main (){
//	cin >> n;
//	int x,k;
//	cin >> x;
//	Node* h = makeNode(x);
//	Node*p =h;
//	for(int i=1;i<n;i++){
//		cin >> x;
//		p=addElement(p,x);
//	}
//	cin >> k >> x;
//	if(k==0){
//		h=addHead(h,x);
//	} else if (k==n){
//		h=addTail(h,x);
//	} else {
//		h=addAt(h,x,k);
//	}
//	printList(h);
	
	
	int n, x, k;
	cin >> n;
	cin >> x;
	Node *h = makeNode(x);
	Node *q = h;
	for (int i = 1; i < n; i++){
		cin >> x;
		//addElement: pointer points at tail; addLast: head
//		q = addElement(q, x);
		h = addLast(h,x);
	}
	printList(h);
	h = remove(h,3);
	printList(h);
	h = removeRecursive(h,2);
	printList(h);
	h = insertBefore(h,3,4);
	printList(h);
	h = insertBeforeR(h,9,5);
	printList(h);
	h = insertAfter(h,100,6);
	printList(h);
	h = insertAfterR(h,1000,6);
	printList(h);
	h = reverse(h);
	printList(h);
	sum(h);
	int rs=sum(h);
	cout << rs << endl;
	int rss=sumRecursive(h);
	cout << rss;
	
	cin >> k;
	q = getNode(h,k);
	cout << q->value;
	
//	if(k==0) h=removeHead(h);
//	else if (k==n-1) h=removeTail(h);
//	else {
//		h=removeAt(h,k);
//	}
//	printList(h);

//	cin >> u;
//  	h = deleteBigger(h,getNode(h,u)->value);
//	printList(h);
	return 0;
	
}
