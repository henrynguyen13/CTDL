#include<stdio.h>
#define N 1000000
int a[N];
int n;
int ans;
void input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
void maxsq(){
	int S =a[1];
	for(int i=2;i<=n;i++){
		if(S>0){
			S=S+a[i];
		} else {
			S=a[i];
		}
		ans=ans<S?S:ans;
	}
	printf("%d",ans);
}
int main (){
	input();
	maxsq();
	return 0;
	
}
