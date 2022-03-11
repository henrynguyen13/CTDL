#include<stdio.h>
#define N 1000001
int n;
int a[N];
int ans;
int start_index[N];
int select;

void input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}

void maxSeq(){
	int s=a[1]; start_index[1]=1;
	ans =-1000000;
	for(int i=2;i<=n;i++){
		if(s>0) {
		s+=a[i]; start_index[i]=start_index[i-1];
		}	
		else {
		s=a[i];start_index[i]=i;	
		}
		if(ans<s){
		ans=s;select=i;	
		} 
	}
	for(int i=start_index[select];i<=select;i++)
		printf("%d ",a[i]);
	printf("\nweigth = ");
	printf("%d",ans);
	
}
int main () {
	input();
	maxSeq();
	return 0;
}
