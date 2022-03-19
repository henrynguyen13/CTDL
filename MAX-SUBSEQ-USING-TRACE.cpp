Problem: Given an integers sequence a=(a1,a2,…,an). A subsequence of a is defined to be ai,ai+1,…,aj. 
	The weight of a subsequence is the sum of its elements. Find the subsequence having the highest weight.

Input
Line 1 contains n (1≤n≤106)
Line 2 contains a1,…,an (−500≤ai≤500)
Output
Write the weight of the highest subsequence found.

#include<stdio.h>
#define N 100001
int n;
int a[N];
int start_index[N];// chỉ số bắt đầu lời giải bài toán con i
int select;// chỉ số của bài toán con lấy làm lời giải

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
