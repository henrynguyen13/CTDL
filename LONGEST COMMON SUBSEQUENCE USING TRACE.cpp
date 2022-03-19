Problem: A subsequence of a given sequence S=S1,…,Sn is obtained by removing some elements from S. 
	Given two sequence of integers X=(X1,…,Xn) and Y=(Y1,…,Ym). Find the longest common subsequence of X and Y.
	
Input
Line 1 contains n and m (1≤n,m≤104)
Line 2 contains X1,…,Xn
Line 3 contains Y1,…,Ym
Output
Write the length of the longest subsequence of the given sequences
input
7 10
3 7 2 5 1 4 9
4 3 2 3 6 1 5 4 9 7
output
9 4 1 2 3 
5

#include<stdio.h>
#define N 10001

int x[N];
int y[N];
int s[N][N];
int n,m;
int trace[N][N]; // truy vết từ ngược từ s[n][m]
void input(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	for(int j=1;j<=m;j++){
		scanf("%d",&y[j]);
	}
}

void solve(){
	for(int i=0;i<=n;i++) s[i][0]=0;
	for(int j=0;j<=m;j++) s[0][j]=0;
	int ans=0;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(x[i]==y[j]){
				s[i][j]=s[i-1][j-1]+1;
				trace[i][j]='D';
			} else {
			 	if(s[i-1][j]>s[i][j-1]) {
			 		s[i][j]=s[i-1][j];
			 		trace[i][j]='U';
				 } else {
				 	s[i][j]=s[i][j-1];
				 	trace[i][j]='L';
				 }
			}
			ans=s[i][j]>ans?s[i][j]:ans;
		}
	}
	int i=n;
	int j=m;
	while(i>=1 && j>=1){
		if(trace[i][j]=='D') {		
			printf("%d ",x[i]); i=i-1;j=j-1;
		} else if(trace[i][j]=='U') i=i-1;
		else if(trace[i][j]=='L') j=j-1;
	}
	printf("\n");
	printf("%d",ans);	
}

int main (){
	input();
	solve();
	return 0;
}
