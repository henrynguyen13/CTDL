#include<stdio.h>
#define N 30
#define INF 1000000
int n,m; //n: so thanh pho
int x[N]; //model a solution x[1]- >x[2] ->x[3]->..->x[1]
int c[N][N];
int mark[N]; // mark[v] =1 da den tham
int f; // do dai hanh trinh da di duoc(update lien tuc trong qua trinh duyet)
int f_min; //do dai hanh trinh ngan nhat
int cm;

void input(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			c[i][j]=INF;
	cm=INF;
	for(int k=1;k<=m;k++){
		int i,j,d;
		scanf("%d%d%d",&i,&j,&d);
		c[i][j]=d;
		if(c[i][j]<cm){
			cm=c[i][j];
		}
	}
	
}
void updateBest(){ // boi vi k==n tuc da di den x[n] roi
	if(f+c[x[n]][x[1]] <f_min){
		f_min = f+c[x[n]][x[1]];
	}
}
void Try(int k){ //try all values forx[k
	for(int v=1;v<=n;v++){
		if(mark[v]==0){
			x[k]=v;
			f=f+c[x[k-1]][x[k]];
			mark[v]=1;
			if(k==n) updateBest();
			else{
				int gk=f+cm*(n-k+1);
				if(gk<f_min){
					Try(k+1);
				}	
			}
			f=f-c[x[k-1]][x[k]];
			mark[v]=0;
			
		}
	}
}
int main (){
	input();
	f=0;
	f_min=INF;
	for(int v=1;v<=n;v++){
		mark[v]=0;
	}
	x[1]=1;mark[1]=1;
	Try(2);
	printf("%d",f_min);
	return 0;
}
