#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> gr;
vector<int> topo;
class KhanAlgo
{
public: 
    void AddEdge(int u, int v){
        gr[u].push_back(v);
    }
public:
    void init(int n){
        gr.resize(n+1);
        topo.clear();
        return;
    }


public:
    void bfS(vector<int>& indeg, int n){
       queue<int> q;
       for(int i = 0; i < n; i++){
            if(indeg[i] == 0)
                q.push(i);
       }
       
       while (!q.empty())
       {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int& v: gr[node]){
                indeg[v]--;
                if(indeg[v] == 0)
                    q.push(v);
            }
            
       }
       return;
    }

};
int main(){
    
    KhanAlgo* obj = new KhanAlgo();

    int n, e;
    cin >> n >> e;
    obj->init(n);
    int u, v;
    vector<int> indegree(n, 0);
    for(int i =0 ; i < e; ++i){
        cin >> u >> v;
        // Add a edge from u -> v
        obj->AddEdge(u, v);
        indegree[v]++;

    }
    obj->bfS(indegree, n);
    for(int& i : topo){
        cout << i << " ";
    }

    return 0;
}