#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,M;
int h(char*s){
	int m = strlen(s);
	int ans=0;
	for(int i=0;i<m;i++){
		ans=ans*256+s[i];
		ans=ans % M;
	}
	return ans;
}

void input(){
	scanf("%d%d",&n,&M);
	char s[201];
	for(int i=0;i<n;i++){
		scanf("%s",s);
		printf("%d\n",h(s));
	}
	
}
int main (){
	input();
	return 0;
}
