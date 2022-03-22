#include <stdio.h>
int cnt=0;
int x[31],t[31],n;
void input()
{
      scanf("%d",&n);
      x[0]=1;
      t[0]=0;
}
int check(int v,int i){
	return 1;
}
void solution(int k)
{	
	cnt+=1;
      printf("\nSolution %d: %d = ",cnt,n);
      for (int i=1;i<k;i++) printf(" %d + ",x[i]);
      printf(" %d",x[k]);
}
void Try(int k)
{
      for(int v=x[k-1];v<=((n-t[k-1])/2);v++)
      {
        if(check(v,k)){
        	x[k]=v;
            t[k]=t[k-1]+v;
		}
		if(k==n) solution(k);
		else{
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
