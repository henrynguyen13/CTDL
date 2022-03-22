#include <bits/stdc++.h>
using namespace std;
const int N =1e3;
set<int> A[N];// A[v] is the set of adjacent nodes to
int n,m;// number of nodes and edges

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
void euler(){
    stack<int> S, CE;
    S.push(1);
    while(!S.empty()){
        int  v= S.top();
        if(A[v].size() > 0){
            int u = *A[v].begin();
            S.push(u);
            A[u].erase(v); A[v].erase(u);// remove edge (u,v)
        }else{
            S.pop();
            CE.push(v);
        }
    }
    cout << "euler cycle: ";
    while(!CE.empty()){
        int v = CE.top(); CE.pop();
        cout << v << " ";
    }
}
int main(){
    freopen("euler.txt","r",stdin);
    input();
    printGraph();
    euler();
    return 0;
}
