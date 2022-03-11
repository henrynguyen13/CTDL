#include<stdio.h>
#include<stdlib.h>
#define N 100001
#define INF 1000001
typedef struct Arc{
	int node;
	int weight;
	struct Arc*next;
}Arc;

int n,m;
Arc*A[N];
int s,t;

//data structure for Dijkstra
int d[N],p[N];
int fixed[N];//fixed[v]=1 means that the shortest path from s to v is found




Arc* insert(int _node,int _weight,Arc*h){
	//Chen vao dau
	Arc*p=(Arc*)malloc(sizeof(Arc));
	p->node=_node;
	p->weight=_weight;
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
		printf("A[%d]: ",v);
		for(Arc*p=A[v];p!=NULL;p=p->next){
			printf("(%d,%d)",p->node,p->weight);
		}
		printf("\n");
	}
}
int selectMin(){
	int minD=INF;int sel=-1;
	//return the node having smallest value of d in the non-fixed set
	for(int v=1;v<=n;v++){
		if(fixed[v]==0){
			if(d[v]<minD){
				minD=d[v];
				sel=v;
			}
		}
	}
	return sel;
}
void dijkstra(){
	//initialization
	for(int v=1;v<=n;v++){
		d[v]=INF;p[v]=-1;
		fixed[v]=0;//not found min 
	}
	for(Arc*p=A[s];p!=NULL;p=p->next){
		int v=p->node;int w=p->weight;
		d[v]=w;
	}
	d[s]=0;fixed[s]=1;
	//loop
	while(1){
		int u=selectMin();
		if(u==-1) break; //tat ca dinh da tim duoc duong di ngan nhat
		if(u==t) break;
		fixed[u]=1;
		for(Arc*p=A[u];p!=NULL;p=p->next){
			int v=p->node;int w=p->weight;
			if(fixed[v]==0){
				if(d[v]>d[u]+w){
					d[v]=d[u]+w;
				}
			}
		}
	}
	if(d[t]==INF) printf("-1");
	else printf("%d",d[t]);
}
int main(){
	input();
	printGraph();
	dijkstra();
	return 0;
}
