#include<bits/stdc++.h>
using namespace std;

void DFS(vector<int>Graph[],int n,int vertex){
    bool visited[vertex];
    stack<int>stk;
    visited[n] = true;
    int item = 0;
    stk.push(n);
    cout << "Graph treversing with DFS : ";
    while(!stk.empty()){
        n = stk.top();
        stk.pop();
        cout << n << " ";
        for(int i = 0; i < Graph[n].size(); i++){
            item = Graph[n][i];
            if(!visited[item]){
                visited[item] = true;
                stk.push(item);
            }
        }
    }
}

auto create_graph(vector<int>Graph[],int edge){
    for(int i = 0; i < edge; i++){
        int u,v; cin >> u >> v;
        Graph[u].push_back(v);
    }
    return Graph;
}

int main(){

    int vertex,edge,src;

    cout << "Enter vertex : ";
    cin >> vertex ;

    cout << "Enter edge : ";
    cin >> edge ;

    vector<int> Graph[vertex];
    
    auto g = create_graph(Graph,edge);

    cout << "Enter source : ";
    cin >> src;

    DFS(g,src,vertex);
    
    return 0;
}
