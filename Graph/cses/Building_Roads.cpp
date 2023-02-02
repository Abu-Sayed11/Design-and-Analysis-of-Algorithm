#include<bits/stdc++.h>
using namespace std;

int vertex,edge,u,v;
vector<bool> visited(100001,false);

void dfs(int s,vector<int>Graph[]){
    visited[s] = true;
    for(auto i : Graph[s]){
        if(!visited[i]){
            dfs(i,Graph);
        }
    }
}

int main(){
    cin >> vertex >> edge;
    vector<int> Graph[vertex+1];
    vector<int>road;
    for(int i = 0; i < edge; i++){
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    int cnt = 0;
    for(int i = 1; i <= vertex; i++){
        if(!visited[i]){
            cnt++;
            road.push_back(i);
            dfs(i,Graph);
        }
    }
    cout << cnt - 1 << endl;
    if(cnt > 1){
        int x = road[0];
        int y ;
        for(auto i = 1; i < cnt; i++){
            y = road[i];
            cout << x << " " << y << endl;
            x = y;
        }
    }

    return 0;
}
