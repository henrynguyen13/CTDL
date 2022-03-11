#include<stdio.h>
#define N 10001
int X[N],Y[N];
int n,m;
int S[N][N];
char trace[N][N];
void input(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&X[i]);
	for(int j=1;j<=m;j++) scanf("%d",&Y[j]);
}
void solve(){
	for(int i=0;i<=n;i++) S[i][0]=0;
	for(int j=0;j<=m;j++) S[0][j]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(X[i]==Y[j]){
				S[i][j]=S[i-1][j-1]+1;
				trace[i][j]='D';
			} else{
				if(S[i-1][j]>S[i][j-1]){
					S[i][j]=S[i-1][j];
					trace[i][j]='U';
				} else{
					S[i][j]=S[i][j-1];
					trace[i][j]='L';
				}
			}
		}
	}
	int i=n;
	int j=m;
	while(i>=1 && j>=1){
		if(trace[i][j]=='D'){
			printf("%d ",X[i]);i=i-1;j=j-1;
		} else if(trace[i][j]=='U') {
		i=i-1;
		}
		else if (trace[i][j]=='L') {
		j=j-1;}
	}
	printf("\n");
	
	printf("%d",S[n][m]);
	
}
int main (){
	input();
	solve();
	return 0;
}
