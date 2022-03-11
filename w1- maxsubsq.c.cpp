#include<stdio.h>
#define N 1000001
int a[N];
int n;
int s[N];
void input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
int algo1(){
	int ans=-10000000;
	for(int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			int s=0;
			for(int k=i;k<=j;k++){
				s=s+a[k];
			}
			if(s>ans){
				ans=s;
			}
		}
	}
	return ans;
}
int algo2(){
	int ans=-1000000;
	for(int i=1;i<n;i++){
		int s=0;
		for(int j=i;j<=n;j++){
			s=s+a[j];
			ans=s>ans?s:ans;
		}
	}
	return ans;
}
int algo3(){
	s[1]=a[1];
	int ans=s[1];
	for(int i=2;i<=n;i++){
		if(s[i-1]>0){
			s[i]=s[i-1]+a[i];
		} else {
			s[i]=a[i];
		}
		ans=s[i]>ans?s[i]:ans;
	}
	
	return ans;
}
int main (){
	input();
	int rs=algo3();
	printf("%d",rs);
	return 0;
}
