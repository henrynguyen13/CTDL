#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> A[N];// A[v] is list of adjacent nodes to v
int n,m; // number of nodes and edges of the given graph
bool visited[N]; // visited[v] = true means node v has been visited
int p[N]; // p[v] is the predecessor of v during the BFS
void input(){
    cin >> n >> m;
    for(int i = 1; i<= m; i++){
        int u,v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}
void printGraph(){
    for(int v = 1;  v <= n; v++ ){
        cout << "A[" << v << "] : ";
        for(int i = 0; i < A[v].size(); i++){
            int u = A[v][i];
            cout << u << " ";
        }
        cout << endl;
    }
}
void BFS(int s){
    queue<int> Q;
    visited[s] = true;
    Q.push(s);
    p[s] = 0;
    cout << s << " ";
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int i = 0; i < A[u].size(); i++){
            int  v = A[u][i];
            if(!visited[v]){
                    cout <<  v << " ";
                visited[v] = true;
                p[v] = u;
                Q.push(v);
            }
        }
    }
}
void findPath(int s, int v){
    for(int  v = 1;  v <= n; v++) visited[v] = false;
    BFS(s);
    if(visited[v] == false) cout << "NOT FOUND path from " << s << " to " << v << endl;
    else{
        stack<int> S;
        cout << "Path from " << s << " to " <<  v << " is : ";
        int x = v;
        while(x != 0){
            //cout << x << " ";
            S.push(x);
            x = p[x];
        }
        while(!S.empty()){
            int x = S.top(); S.pop();
            cout << x << " ";
        }
    }
}


int main(){
    freopen("graph-bfs.txt","r",stdin);
    input();
    printGraph();

    for(int  v= 1; v <= n; v++) visited[v] = false;

    for(int s = 1; s <= n; s++) if(!visited[s])
        BFS(s);

     findPath(1,4);
    return 0;
}
