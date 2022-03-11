#include<stdio.h>
#include<stdlib.h>
#define N 100001
#define INF 1000001
typedef struct Arc{
	int node;//other end-point;
	int weight;
	struct Arc*next;
}Arc;

int s,t;//dinh dau, dinh cuoi

int n,m;//number of nodes and arcs
Arc*A[N]; //A[v] is the pointer to the first node in the adjacent list of v

//data structures of Min-heap
int node[N];
int idx[N];
int sH;//size of Heap

//data structures for Dijkstra
int d[N],p[N];
int fixed[N];//fixed[v]=1 means that the shortest path from s to v is found

void swap(int i,int j){
	int tmp=node[i];node[i]=node[j];node[j]=tmp;
	idx[node[i]]=i;idx[node[j]]=j;
}

void upHeap(int i){
	if(i==0) return;
	while(i>0){
		int pi=(i-1)/2; //parent
		if(d[node[i]]<d[node[pi]]){
			swap(i,pi);
		} else {
			break;
		}
		i=pi;
	}
}

void downHeap(int i){ //i start: 0
	int L=2*i+1;
	int R=2*i+2;
	int minIdx=i;
	if(L<sH && d[node[L]]<d[node[minIdx]]) minIdx=L;
	if(R<sH && d[node[R]]<d[node[minIdx]]) minIdx=R;
	if(minIdx!=i){
		swap(i,minIdx);
		downHeap(minIdx);
	}
}

void insertHeap(int v,int k){
	//add element key k,value v into HEAP
	d[v]=k;
	node[sH]=v;
	idx[node[sH]]=sH;
	upHeap(sH);
	sH++;
}
int inHeap(int v){
	return idx[v]>=0;
}
void updateKey(int v,int k){
	if(d[v]>k){
		d[v]=k;
		upHeap(idx[v]);
	} else {
		d[v]=k;
		downHeap(idx[v]);
	}
}

int deleteMin(){
	if(sH<=0) return -1;
	int sel_node=node[0];
	swap(0,sH-1);
	sH--;
	downHeap(0);
	return sel_node;
}

//insert an element to the first position of a linked list head by h
Arc* insert(int _node,int _weight,Arc*h){
	Arc*p=(Arc*)malloc(sizeof(Arc));
	p->node=_node;p->weight=_weight;
	p->next=h;
	return p;
}
void input(){
	scanf("%d%d",&n,&m);
	for(int u=1;u<=n;u++) A[u]=NULL;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		//add new arc to the adjacent list of u
		A[u]=insert(v,w,A[u]);
	}
	scanf("%d%d",&s,&t);
}

void printGraph(){
	for(int v=1;v<=n;v++){
		printf("A[%d]:",v);
		for(Arc*p=A[v];p!=NULL;p=p->next){
			printf("(%d,%d)",p->node,p->weight);
		}
		printf("\n");
	}
}
void initHeap(){
	sH=0;
	for(int i=1;i<=n;i++) {
		idx[i]=-1;//no element in heap
	}
}
void dijkstra(){
	for(int v=1;v<=n;v++){
		fixed[v]=0;d[v]=INF;
	}
	initHeap();
	d[s]=0;fixed[s]=1;
	for(Arc*p=A[s];p!=NULL;p=p->next){
		int v=p->node;int w=p->weight;
		d[v]=w;
		insertHeap(v,d[v]);
	}
	while(1){
		int u=deleteMin();
		if(u==-1) break;
		if(u==t) break;
		fixed[u]=1;// the shortest path from s to u is found, d[u] is fixed
		for(Arc*q=A[u];q!=NULL;q=q->next){
			int v=q->node;int w=q->weight;
			if(fixed[v]==0){
				//shortest path from s to v is not found
				int newKey=d[v];
				if(d[v]>d[u]+w){
					newKey=d[u]+w;p[v]=u;
				}
				if(!inHeap(v)){
					//v chua nam trong heap
					insertHeap(v,newKey);
				} else {
					updateKey(v,newKey);
				}
			}
		}
	}
	if(d[t]==INF) printf("-1");else printf("%d",d[t]);
}


int main (){
	input();
//	printGraph();
	dijkstra();
	return 0;
}
