#include<stdio.h>
#include<stdlib.h>
#define N 100001

int n,m;

typedef struct Edge{
	int u,v;
}Edge;

//data structure for disjoin set
int p[N],r[N];

Edge E[N];//array representing the list of edges

Edge ET[N];
int cnt;//number of edges of ET (set of edges of the final...)
int x[N];//model the solution 1<=x[1]<x[2]<..<x[n-1] (chi so)

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
void input(){
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&E[i].u,&E[i].v);
	}
}
void solution(){
	cnt+=1;
//	for(int i=1;i<=n-1;i++){
//		printf("(%d,%d),",E[x[i]].u,E[x[i]].v);
//	}
//	printf("\n");
}
int check(int val,int k){
	//aware of (E[x[1]],E[x[2]],..,E[x[k-1]]), check if (E[x[1]],E[x[2]],..,E[x[k-1]],E[val]) create a cycle
	makeSet();
	for(int i=1;i<=k-1;i++){
		int u=E[x[i]].u;int v=E[x[i]].v;
		int r1=findSet(u);
		int r2=findSet(v);
		if(r1==r2) return 0; //because make a cycle
		unify(r1,r2);
	}
	if(findSet(E[val].u)==findSet(E[val].v)) return 0;
	return 1;
}
void Try(int k){
	for(int v=x[k-1]+1;v<=m;v++){
		if(check(v,k)){
			x[k]=v;
			if(k==n-1){
				solution();
			} else {
				Try(k+1);
			}
		}
	}
}
void solve(){
	cnt=0;
	x[0]=0;
	Try(1);
	printf("%d",cnt);
}
int main (){
	input();
	solve();
	return 0;
}
