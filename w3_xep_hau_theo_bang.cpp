#include<stdio.h>
int n;
int x[100];
int cnt;
int table[100][100];
void solution(){
//	for(int i=1;i<=n;i++){
//		printf("%d ",x[i]);
//	}
//	printf("\n");
cnt+=1;
for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		table[i][j]=0;
for(int i=1;i<=n;i++)
	table[x[i]][i]=1;
for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		printf("%d ",table[i][j]);
	}
	printf("\n");
}
printf("----------\n");
}
int check(int v,int k){
	for(int i=1;i<=k-1;i++){
			if(x[i]==v) return 0; // v dong vai tro x[k], nhung luc nay x[k] chua nhan gia tri v
			if(x[i]+i==v+k) return 0;
			if(x[i]-i==v-k) return 0;
		}
		return 1;
}
void Try(int k){
	for(int v=1;v<=n;v++){
		if(check(v,k)){
			x[k]=v;
			if(k==n) solution();
			else Try(k+1);
			
		}
	}
}
int main (){
	n=4;
	cnt=0;
	Try(1);
	printf("Number of solution = %d\n",cnt);
	return 0;
}
