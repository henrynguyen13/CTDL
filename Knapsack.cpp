#include<stdio.h>
#define N 100
#include<stdlib.h>

int n,c;
int p[N];
int w[N];
int f,f_best;
int x[N];

void input(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
}
void sort(){
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			double a = p[i]*1.0/w[i]; //nhan 1.0 de dam bao ra so thuc
			double b = p[j]*1.0/w[j];
			if(a<b){
				if(p[i]/w[i]<p[j]/w[j]){
				int tmp=p[i];p[i]=p[j];p[j]=tmp;
				tmp=w[i];w[i]=w[j];w[j]=tmp;
			}
		}
	}
}
}
void updateBest(){
	if(f>f_best){
		f_best=f;
		printf("Update best:");
		for(int i=1;i<=n;i++) printf("%d ",x[i]);
		printf("f_best = %d\n",f_best);
	}
}
void Try(int k){
	for(int v=c/w[k];v>=0;v--){
		x[k]=v;
		c=c-w[k]*x[k];
		f=f+p[k]*x[k];
		if(k==n) updateBest();
		else{
			double g = f*(p[k+1]*c)*1.0/w[k+1];
			if(g>f_best)
				Try(k+1);
		}
		f=f-p[k]*x[k];
		c=c+w[k]*x[k];
	}
}
int main (){
	char* filename = "knap.txt" ;
	freopen(filename,"r",stdin);
	input();
	sort();
	f=0;f_best = -1000000;
	Try(1);
	return 0;
}
