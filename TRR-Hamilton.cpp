#include <bits/stdc++.h>
using namespace std;
const int N =1e3;
set<int> A[N];// A[v] is the set of adjacent nodes to
int n,m;// number of nodes and edges
int x[N];
bool visited[N];

void input(){
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= m; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        A[u].insert(v);
        A[v].insert(u);
    }
}
void printGraph(){
    for(int  v = 1; v <= n; v++){
        cout << "A[" << v << "]: ";
        for(set<int>::iterator p = A[v].begin(); p != A[v].end(); p++){
            cout << *p << " ";
        }
        cout << endl;
    }
}
void solution(){
    for(int i = 1; i <= n; i++) cout << x[i] << " "; cout << endl;
}
void Try(int k){
    for(set<int>::iterator p = A[x[k-1]].begin(); p != A[x[k-1]].end(); p++){
        int v = *p;
        if(!visited[v]){
            x[k] = v;
            visited[v] = true;
            if(k == n){
                if(A[x[1]].find(x[n]) != A[x[1]].end()){
                    solution();
                }
            }else{
                Try(k+1);
            }
            visited[v] = false;
        }
    }
}
int main(){
    freopen("ham.txt","r",stdin);
    input();
    printGraph();
    x[1] = 1;
    for(int  v = 1; v <= n; v++) visited[v] = false;
    visited[1] = true;
    Try(2);
    return 0;
}
