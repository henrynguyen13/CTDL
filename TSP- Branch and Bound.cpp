Một người du lịch xuất phát từ thành phố thứ nhất muốn đi thăm quan tất cả n−1 thành phố khác. mỗi thành phố đúng một lần, rồi quay trở lại thành phố xuất phát.

Yêu cầu: Cho biết chi phí đi lại giữa các thành phố, hãy giúp người du lịch tìm hành trình với tổng chi phí là nhỏ nhất.

Input
Dòng đầu tiên chứa hai số nguyên dương n,m cách nhau bởi dấu cách (n≤20,m<400).

m dòng tiếp theo mỗi dòng chứa ba số nguyên dương i,j,c (i,j≤n,c≤10^6) biểu thị chi phí đi trực tiếp từ thành phố i đến thành phố j là c.

Lưu ý: nếu từ thành phố i đến thành phố j nào không mô tả chi phí đi lại thì có nghĩa là không có đường đi trực tiếp từ i đến j.

Output
Ghi ra duy nhất một số là tổng chi phí hành trình nhỏ nhất tìm được.
	
Ex: Input: 
2 2
1 2 3
2 1 2
Output: 5

#include<stdio.h>
#define N 30
#define INF 1000000
int n,m; //n: so thanh pho
int x[N]; //model a solution x[1]- >x[2] ->x[3]->..->x[1]
int c[N][N];
int mark[N]; // mark[v] =1 da den tham
int f; // do dai hanh trinh da di duoc(update lien tuc trong qua trinh duyet)
int f_min; //do dai hanh trinh ngan nhat
int cm;

void input(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			c[i][j]=INF;
	cm=INF;
	for(int k=1;k<=m;k++){
		int i,j,d;
		scanf("%d%d%d",&i,&j,&d);
		c[i][j]=d;
		if(c[i][j]<cm){
			cm=c[i][j];
		}
	}
	
}
void updateBest(){ // boi vi k==n tuc da di den x[n] roi
	if(f+c[x[n]][x[1]] <f_min){
		f_min = f+c[x[n]][x[1]];
	}
}
void Try(int k){ //try all values forx[k
	for(int v=1;v<=n;v++){
		if(mark[v]==0){
			x[k]=v;
			f=f+c[x[k-1]][x[k]];
			mark[v]=1;
			if(k==n) updateBest();
			else{
				int gk=f+cm*(n-k+1);
				if(gk<f_min){
					Try(k+1);
				}	
			}
			f=f-c[x[k-1]][x[k]];
			mark[v]=0;
			
		}
	}
}
int main (){
	input();
	f=0;
	f_min=INF;
	for(int v=1;v<=n;v++){
		mark[v]=0;
	}
	x[1]=1;mark[1]=1;
	Try(2);
	printf("%d",f_min);
	return 0;
}
