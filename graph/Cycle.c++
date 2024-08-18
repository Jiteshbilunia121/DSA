#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> gr;
class Cyclecheck{

public: 
    void AddEdge(int u, int v){
        gr[u].push_back(v);
    }
public:
    void init(int n){
        gr.resize(n+1);
    }
public:
    bool dfs(int node,vector<bool>& vis, vector<bool>& path){ 

        vis[node] = 1;
        path[node] = 1;
        for(int& v: gr[node]){
            if(!vis[v]){
                bool nbr = dfs(v, vis, path);
                if(nbr)
                    return true;
            }
            else if( path[node]){
                return true;
            }
        }
        path[node] = 0;
        return false;
    
    }



};
int main(){

    Cyclecheck* obj = new Cyclecheck();
    int n, e;
    cin >> n >> e;
    obj->init(n);
    int u, v;
    for(int i =0 ; i < e; ++i){
        cin >> u >> v;
        // Add a edge from u -> v
        obj->AddEdge(u, v);

    }
    vector<bool> vis(n, 0);
    vector<bool> path(n, 0);
    for(int i = 0; i < n; i++){
        if(obj->dfs(i, vis, path)){
            cout <<  "Cycle is present";
            return 0;
        }
    }
    cout << "Not present" << endl;

    return 0;
}