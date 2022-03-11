#include<stdio.h>
#define K 100000

int A[K];
int N;
int TA[K];
int L,R;
void input(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&A[i]);
	}	
}

void swap(int i,int j){
	int tmp = A[i];
	A[i]=A[j];
	A[j]=tmp;
}
void selectionSort(int N){ //selection sort 
	for(int i = 1;i<N;i++){
		int min = i;
		for(int j=i+1;j<=N;j++){
			if(A[min] > A[j]){
				min = j;
			}
		}
		int tmp = A[min];
		A[min]=A[i];
		A[i]=tmp;
	}
}

void insertionSort(int A[],int N){ //insertion sort 
	for(int i=2;i<=N;i++){
		int last = A[i];
		int j = i;
		while(j>1 && A[j-1]>last){
			A[j]=A[j-1];
			j--;
		} 
		A[j]=last;
	}
}	

void merge(int A[],int L,int M,int R){ //merge sort 
	int i= L;
	int j = M+1;
	for(int k=L;k<=R;k++){
		if(i>M){
			TA[k]=A[j];
			j++;
		}
		else if (j>R){
			TA[k]=A[i];
			i++;
		}
		else{
			if(A[i]<A[j]){
				TA[k]=A[i];
				i++;
			}
			else{
				TA[k]=A[j];
				j++;
			}
		} 
	}
	for(int k=L;k<=R;k++){
		A[k]=TA[k];
	}
}
void mergeSort(int A[],int L,int R){
	if(L<R){
		int M = (L+R)/2;
		mergeSort(A,L,M);
		mergeSort(A,M+1,R);
		merge(A,L,M,R);
	}
}

//quick sort
int partition(int A[],int L,int R,int indexPivot){
	int pivot = A[indexPivot];
	swap(indexPivot,R);
	int storeIndex = L;
	for(int i = L;i<=R-1;i++){
		if(A[i] < pivot){
			swap(storeIndex,i);
			storeIndex++;
		}
	}
	swap(storeIndex,R);
	return storeIndex;
}
void quickSort(int A[],int L,int R){
	if(L<R){
		int index = (L+R)/2;
		index = partition(A,L,R,index);
		if(L<index){
			quickSort(A,L,index-1);
		}
		if(index < R){
			quickSort(A,index+1,R);
		}
	}
}



void print(){
	for(int i = 1;i<=N;i++){
		printf("%d ",A[i]);
	}
}
int main (){
	input();
	//mergeSort(A,1,N);
	quickSort(A,1,N);
	print();
	return 0;
}
