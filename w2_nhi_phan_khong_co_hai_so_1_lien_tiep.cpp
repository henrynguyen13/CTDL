#include<stdio.h>
#define N 20
int x[N];
int n;
int check(int v,int k){
	if(x[k-1]+v<=1) return 1;
	else return 0;
}
void solution(){
	for(int i=1;i<=n;i++){
		printf("%d",x[i]);
	}
	printf("\n");
}
void Try(int k){
	for(int v=0;v<=1;v++){
		if(check(v,k)){
			x[k]=v;
			if(k==n) solution();
			else {
				Try(k+1);
			}
		}
	}
}
int main (){
	n=4;
	Try(1);
}


