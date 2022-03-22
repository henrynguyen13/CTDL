#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> A[N];// A[v] is list of adjacent nodes to v
int n,m; // number of nodes and edges of the given graph
bool visited[N]; // visited[v] = true means node v has been visited
int p[N]; // p[v] is the predecessor of v during the BFS
int d[N], f[N];
int t;// global discrete time variable
void input(){
    cin >> n >> m;
    for(int i = 1; i<= m; i++){
        int u,v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}
void DFS(int s){
    t += 1; visited[s] = true;
    d[s] = t;
    for(int i = 0; i < A[s].size(); i++){
        int  v = A[s][i];
        if(visited[v]==false){
            p[v] = s;
            DFS(v);
        }
    }
    t += 1;
    f[s] = t;
}
void DFS(){
    for(int  v= 1; v <= n; v++) visited[v] = false;

    t = 0;
    for(int v = 1; v <= n; v++) if(visited[v] == false)
        DFS(v);

    for(int v = 1;  v <= n; v++){
        cout << "node " << v << " d = " << d[v] << " f = " << f[v] << " p = " << p[v] << endl;
    }
}
int main(){
    freopen("graph-bfs.txt","r",stdin);
    input();
    DFS();
    return 0;
}
