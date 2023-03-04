#include <bits/stdc++.h>
using namespace std;

#define ll long long

void dijkstras(vector<pair<ll, ll>> graph[], ll src, ll vertex){

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    vector<ll> distance(vertex+1, LLONG_MAX);
    vector<bool> visited(vertex+1,false);

    pq.push({0, src});
    distance[src] = 0;
    
    while(!pq.empty()){
        ll u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for(auto i : graph[u]){
            ll v = i.first;
            ll wt = i.second;
            if (distance[u] + wt < distance[v]) {
                distance[v] = distance[u] + wt;
                pq.push({distance[v], v});
            }
        }
    }

    for(ll i = 1; i <= vertex; i++){
        cout << distance[i] << " ";
    }

}

int main () 
{
    ll vertex,edge;
    cin >> vertex >> edge;

    vector<pair<ll, ll>> graph[vertex+1];

    for (ll i = 1; i <= edge; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
 
    dijkstras(graph, 1, vertex);

    return 0;
}
