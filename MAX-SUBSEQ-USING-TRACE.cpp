#include<stdio.h>
#define N 100001
int n;
int a[N];
int start_index[N];
int select;

void input () {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}

void solve(){
	int s;
	s=a[1];
	start_index[1]=1;
	int ans=-999999;
	for(int i=2;i<=n;i++){
		if(s>0){
			s+=a[i];
			start_index[i]=start_index[i-1];
		} else {
			s=a[i];
			start_index[i]=i;
		}
		if(s>ans) {
			ans=s;
			select=i;
		}
	}
	printf("%d\n",ans);
	for(int i=start_index[select];i<=select;i++){
		printf("%d ",a[i]);
	}
}
int main (){
	input();
	solve();
	return 0;
}
