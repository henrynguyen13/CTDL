#include<stdio.h>

int k,n;
int x[30];

int check(int v,int i){
	return 1; //ko can cung dc
}
void solution(){
	for(int i=1;i<=k;i++){
		printf("%d ",x[i]);
	}
	printf("\n");
}
void Try(int i){
	for(int v=x[i-1]+1;v<=n-k+i;v++){
		if(check(v,i)) {
			x[i]=v;
			if(i==k) solution();
			else Try(i+1);
			}
		}
	}

int main(){
	scanf("%d%d",&k,&n);
	Try(1);
	return 0;
}
