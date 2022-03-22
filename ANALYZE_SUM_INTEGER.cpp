#include<stdio.h>
int x[100],t[100];
int n;
int k;
int check(int v,int k){
	if(t[k-1]+v<n) return 1;
	return 0;
}
void input()
{
      printf("\nNhap n = ");
      scanf("%d",&n);
      x[0]=1;
      t[0]=0;
}
int cnt=0;
void solution(int k)
{
	  cnt+=1;
      printf("\n TH %d: %d = ",cnt,n);
      for (int i=1;i<k;i++) printf(" %d + ",x[i]);
      printf(" %d",x[k]);
}
void Try(int k){
	for(int v=x[k-1];v<=((n-t[k-1])/2);v++){
		if(check(v,k)){
			x[k]=v;
			t[k]=t[k-1]+v;
			Try(k+1);
		}
	}
		x[k]=n-t[k-1];
      	solution(k);
	}

int main (){
	input();
	Try(1);
	return 0;
}
