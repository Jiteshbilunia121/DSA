#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> gr[n];
    // gr[i].first = edge from i to gr[i].first
    // gr[i].second = edge weight from i tp gr[i].second
    int u, v, wt;
    for(int i = 0; i < e; i++){
        cin >> u >> v >> wt;
        gr[u].push_back(make_pair(v, wt));
        gr[v].push_back(make_pair(u, wt));
    }
    int src = 0;
    vector<int> dist(n, 1e9);
    // Declare a min heap
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>> > pq;
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
            int node =  pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto& v: gr[node]){
                
                if(dis + v.second < dist[v.first]){
                    dist[v.first] = dis + v.second;
                    pq.push({dist[v.first], v.first});
                }
            }

        /* code */
    }

    for(int i = 0; i < n; i++){
        cout << "distance" << "[" << i << "] " << dist[i] << endl;
    }
    

    return 0;
}