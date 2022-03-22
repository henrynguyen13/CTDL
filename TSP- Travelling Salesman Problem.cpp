#include<stdio.h>
#include<stdlib.h>
#define N 30
#define INF 1000000
int n,m;
int x[N];
int c[N][N];
int mark[N];
int f; // do dai hanh trinh da di duoc(update lien tuc trong qua trinh duyet)
int f_min; //do dai hanh trinh ngan nhat
int cm;

void input(){
	cm=1000000;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
			if(i!=j &&c[i][j]<cm) cm=c[i][j];
		}
	}
}
void print(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
}
void updateBest(){
	if(f+c[x[n]][x[1]]<f_min){ //boi vi da den x[n] roi
		f_min = f+c[x[n]][x[1]];
		printf("\nUpdate min:");
		for(int i=1;i<=n;i++) printf("%d ",x[i]);
		printf("\nMin = %d",f_min);
	}
}
void Try(int k){
	for(int v=1;v<=n;v++){
		if(mark[v]==0){
			x[k]=v;
			f=f+c[x[k-1]][x[k]];
			mark[v]=1;
			if(k==n) updateBest();
			else {
				int g = f+cm*(n-k+1);
				if(g<f_min)
					Try(k+1);
				}
			f=f-c[x[k-1]][x[k]];
			mark[v]=0;
			}
			
		}
	}
void genData(char* filename,int n,int MAX_VALUE){
	FILE*f = fopen(filename,"w");
	fprintf(f,"%d\n",n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x=rand()%MAX_VALUE +1;
			if(i==j) x=0;
			fprintf(f,"%d ",x);
		}
		fprintf(f,"\n");
	}
	fclose(f);
}
int main (){
	char*filename = "tsp-15.txt";
//	genData(filename,5,10);
//	return 0;
	
	freopen(filename,"r",stdin);
	input();
	print();
	for(int v=1;v<=n;v++){
		mark[v]=0;
	}
	f=0;f_min=10000000;
	x[1]=1;mark[1]=1;
	Try(2);
	return 0;
}
