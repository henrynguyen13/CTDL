#include<stdio.h>
#define N 100001

int n;
int a[N];
int ta[N];


void swap(int i,int j){
	int tmp=a[i];
	a[i]=a[j];
	a[j]=tmp;
	
}
void input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
void selectionSort(int a[],int n){
	for(int i=1;i<=n;i++){
		int min =i;
		for(int j=i+1;j<=n;j++){
			if(a[min] >a[j]) min=j;
		}
		int tmp=a[min];
		a[min]=a[i];
		a[i]=tmp;
	}
}

void insertionSort(int a[],int n){
	for(int i=2;i<=n;i++){
		int last=a[i];
		int j=i;
		while(j>1 && a[j-1]>last){
			a[j]=a[j-1];
			j--;
		}
		a[j]=last;
	}
}

void bubbleSort(int a[],int n){
	int swapped;
	do{
		swapped=0;
		for(int i=1;i<n;i++){
			if(a[i]>a[i+1]){
				int tmp=a[i];
				a[i]=a[i+1];
				a[i+1]=tmp;
				swapped=1;
			}
		}
	} while (swapped==1);
}

void merge(int a[],int L,int M,int R){
	int i=L;
	int j=M+1;
	for(int k=L;k<=R;k++){
		if(i>M){
			ta[k]=a[j];j++;
		} else if(j>R){
			ta[k]=a[i];i++;
		} else {
			if(a[i]>a[j]){
				ta[k]=a[j];j++;
			} else {
				ta[k]=a[i];i++;
			}
		}
	}
	for(int k=L;k<=R;k++){
		a[k]=ta[k];
	}
}
void mergeSort(int a[],int L,int R){
	if(L<R){
		int M=(L+R)/2;
		mergeSort(a,L,M);
		mergeSort(a,M+1,R);
		merge(a,L,M,R);
	}
}
int partition(int a[],int L,int R,int indexPivot){
	int pivot= a[indexPivot];
	swap(indexPivot,R);
	int storeIndex=L;
	for(int i=L;i<=R-1;i++){
		if(a[i]<pivot){
			swap(storeIndex,i);
			storeIndex++;
		}
	}
	swap(storeIndex,R);
	return storeIndex;
}
void quickSort(int a[],int L,int R){
	if(L<R){
		int index=(L+R)/2;
		index=partition(a,L,R,index);
		if(L<index){
			quickSort(a,L,index-1);
		} 
		if(index<R){
			quickSort(a,index+1,R);
		}
	}
}

void heapify(int a[],int i,int n){
	int L=2*i;
	int R=2*i+1;
	int max=i;
	if(L<=n && a[L]>a[max]){
		max=L;
	}
	if(R<=n && a[R]>a[max]){
		max=R;
	}
	if(max!=i){
		swap(i,max);
		heapify(a,max,n);
	}
}
void buildHeap(int a[],int n){
	for(int i=n/2;i>=1;i--){
		heapify(a,i,n);
	}
}
void heapSort(int a[],int n){
	buildHeap(a,n);
	for(int i=n;i>=1;i--){
		swap(1,i);
		heapify(a,1,i-1);
	}
}
void output(){
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
}



int main (){
	input();
//	selectionSort(a,n);
//	insertionSort(a,n);
//	bubbleSort(a,n);
//	mergeSort(a,1,n);
//	quickSort(a,1,n);
	heapSort(a,n);
	output();
	
	return 0;
	
}
