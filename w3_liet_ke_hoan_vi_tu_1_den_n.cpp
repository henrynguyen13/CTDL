#include<stdio.h>
int x[100];
int n;
int mark[100];


void solution(){
	for(int i=1;i<=n;i++){
		printf("%d",x[i]);
	}
	printf("\n");
}
void Try(int k){
	for(int v=1;v<=n;v++){
		if(!mark[v]){
			x[k]=v;
			mark[v]=1;
			if(k==n) solution();
			else Try(k+1);
			mark[v]=0;
		}
	}
}
int main (){
	n=4;
	for(int i=1;i<=n;i++){
		mark[i]=0;
	}
	Try(1);
	return 0;
}
