#include<bits/stdc++.h>
using namespace std;

int N = 100;

vector<bool> visited(N,false);

void dfs(vector<int> Graph[],int src){
    visited[src] = true;
    for(auto i : Graph[src]){
        if(!visited[i]){
            dfs(Graph,i);
        }
    }
}

int main(){
    
    int n,m;
    cin >> n >> m;

    vector<int> Graph[n + 1];

    for(int i = 0; i < m ; i++){
        int u,v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    int cnt = 0;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt++;
            dfs(Graph,i);
        }
    }
    cout << cnt << endl;

    return 0;
}
