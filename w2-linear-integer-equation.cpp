#include<stdio.h>
int n,M;
int a[20];
int x[20];
int T,R;
int ans;
void readData(){
	scanf("%d%d",&n,&M);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
int check(int v,int k){
	if(k<n) return 1;
	if(T+a[n]*v==M) return 1;
	else return 0;
}
void solution(){
	ans+=1;
	//for(int i=1;i<=n;i++){
//		printf("%d*%d ",a[i],x[i]);
//	}
//	printf("= %d\n",M);
}
void Try(int k){ // try all value for x[k]
	for(int v=1;v<=(M-T-R)/a[k];v++){
		if(check(v,k)){
			x[k]=v;
			T=T+a[k]*x[k];
			R=R-a[k+1];
			if(k==n) solution();
			else Try(k+1);
			T=T-a[k]*x[k];
			R=R+a[k+1];
		}
	}
}
int main (){
	readData();
	T=0;
	R=0;
	for(int i=2;i<=n;i++){
		R=R+a[i];
	}
	Try(1);
	printf("%d",ans);
	return 0;
}
