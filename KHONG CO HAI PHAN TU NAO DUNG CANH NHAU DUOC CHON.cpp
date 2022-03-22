#include<iostream>
using namespace std;

int x[100];
int k, n;

void input(){
	cin >> k >> n;
	for(int i = 0; i <= n; i++){
		x[i] = 0;
	}
}

bool count(){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(x[i] == 1) cnt++;
	}
	if(cnt == k) return true;
	else return false;
}

void solution(){
	if(count()){
		for(int i = 1; i <= n; i++){
			if(x[i] == 1) cout << i << " ";
		}
		cout << endl;
	}
}

bool check(int v, int i){
	if(x[i-1] + v <= 1) return true;
	else return false;
}


void Try(int i){
	for(int v = 1;v>=0;v--){
		if(check(v, i)){
			x[i] = v;
			if(i == n) solution();
			else Try(i+1);
		}
	}
}

int main(){
	input();
	Try(1);
	return 0;
}
