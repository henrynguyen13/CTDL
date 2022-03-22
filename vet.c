#include <stdio.h>

int n;
int arr[100];
int sum = 0, count =0;

void Try(int k) {
    for(int i = 1; i <= n-sum && i <= 6; i++) {
        if((k==1) || (arr[k-1]>1&&i==1) || (arr[k-1]==1&&i>1)) {
            arr[k] = i;
            sum += i;
            if(sum == n) count++;
            else if(k<10 && sum<n) Try(k+1);
            sum -= i;
        }
    }
}

int main() {
    scanf("%d", &n);
    Try(1);
    printf("%d", count);
}
