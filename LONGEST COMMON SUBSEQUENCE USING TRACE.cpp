#include<stdio.h>
#define N 10001

int x[N];
int y[N];
int s[N][N];
int n,m;
int trace[N][N]; 

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
