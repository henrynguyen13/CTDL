#include<stdio.h>
#include<stdlib.h>
#define N 100001

int n,m;

typedef struct Edge{
	int u,v,w;
}Edge;

//data structure for disjoin set
int p[N],r[N];

Edge E[N];//array representing the list of edges
Edge TA[N];// temporary array
Edge ET[N];
int cnt;//number of edges of ET (set of edges of the final...)


void input(){
	scanf("%d%d",&n,&m);
//	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
	}
}
void merge(int L,int M,int R){
	int i=L;int j=M+1;
	for(int k=L;k<=R;k++){
		if(i>M) {
			TA[k]=E[j]; j++;
		} else if (j>R) {
			TA[k]=E[i]; i++;
		} else {
			if(E[i].w< E[j].w){
				TA[k]=E[i];i++;
			} else {
				TA[k]=E[j];j++;
			}
		}
	}
	for(int k=L;k<=R;k++) E[k]=TA[k];
}

void mergeSort(int L,int R){
	if(L<R){
		int M=(L+R)/2;
		mergeSort(L,M);
		mergeSort(M+1,R);
		merge(L,M,R);
	}
}

void print(){
	for(int i=1;i<=m;i++){
		printf("%d %d %d\n",E[i].u,E[i].v,E[i].w);
	}
	
}
void sort(){
	mergeSort(1,m);
}

//implementation of DisjoinSet data structure
void makeSet(){
	for(int v=1;v<=n;v++){
		p[v]=v;
		r[v]=1;
	}
}
int findSet(int x){
	if(x!=p[x]){
		p[x]=findSet(p[x]);
	}
	return p[x];
}

void unify(int r1,int r2){
	if(r[r1]>r[r2]){
		p[r2]=r1;
	} else {
		p[r1]=r2;
		if(r[r1]==r[r2]) r[r2]+=1;
	}
}
//end of implementation DisjointSet


void kruskal(){
	long long W=0;// avoid tran so
	cnt=0;
	makeSet();
	for(int i=1;i<=m;i++){
		int u=E[i].u;int v=E[i].v;
		int r1=findSet(u);int r2=findSet(v);
		if(r1!=r2){
			cnt+=1;
			ET[cnt]=E[i];
			W=W+E[i].w;
			unify(r1,r2);
			if(cnt==n-1) break;
		}
	}
	printf("%llu\n",W);
}

void printResult(){
	for(int i=1;i<=cnt;i++){
		printf("edge(%d,%d) weight=%d\n",ET[i].u,ET[i].v,ET[i].w);
	}
}



int main (){
	input();
	sort();
//	print();
	kruskal();
//	printResult();
	
	return 0;
}
