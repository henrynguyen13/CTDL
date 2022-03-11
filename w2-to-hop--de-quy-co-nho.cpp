#include<stdio.h>
int m[100][100];
int C(int k,int n){
	if(k==0 || k==n){
		m[k][n]=1;
	}
	else{
		if(m[k][n]==-1){
			m[k][n]=C(k-1,n-1)+C(k,n-1);
		}
	}
	return m[k][n];
}

int main(){
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			m[i][j]=-1; //gan -1 tuc la chua gia tri phan tu do chua duoc thuc hien
	
	printf("%d",C(3,5));
	return 0;
		
	
}
