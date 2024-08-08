#include <bits/stdc++.h>
using namespace std;
int timer = 0;
void addegde(vector<int> adj[], int x, int y)
{
    adj[x].push_back(y);
    // adj[y].push_back(x);
    return;
}
void DFS(stack<int> s, vector<int> adjacency[], int k, int visited[], int start[], int end[], int parent[])
{
    long unsigned x, j;
    s.push(k);
    // cout << k << " ";
    start[k] = timer++;
    visited[k] = 1;
    // Using a iterative dfs
    while (!s.empty())
    {
        x = s.top();
        for (j = 0; j < adjacency[x].size(); j++)
        {
            if (visited[adjacency[x][j]] != 1)
                break;
        }
        if (j < adjacency[x].size())
        {
            s.push(adjacency[x][j]);
            // cout<<s.top()<<" ";
            visited[adjacency[x][j]] = 1;
            start[adjacency[x][j]] = timer++;
            parent[adjacency[x][j]] = x;
        }
        else
        {
            s.pop();
            end[x] = timer++;
        }
        // timer++;
    }
    return;
}

int main()
{
    cout << "Enter the vertices and edges number: " << endl;
    int v, e;
    cin >> v >> e;
    vector<int> adjacency[v];
    int visited[v] = {0};
    int start[v];
    int end[v];
    int parent[v];
    for (int i = 0; i < e; i++)
    {
        cout << "enter the vertices to add the edge";
        int a, b;
        cin >> a >> b;
        addegde(adjacency, a, b);
    }
    stack<int> s;
    int k = 0;
    while (k < v)
    {
        if (visited[k] == 0)
        {
            // visited[k]=1
            DFS(s, adjacency, k, visited, start, end, parent);
        }
        k++;
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < adjacency[i].size(); j++)
        {
            if (start[adjacency[i][j]] > start[i] && end[adjacency[i][j]] < end[i] && parent[adjacency[i][j]] == i)
                cout << "(" << i << " " << adjacency[i][j] << ")" << "Tree edge" << endl;
            else if (start[adjacency[i][j]] > start[i] && end[adjacency[i][j]] < end[i] && parent[adjacency[i][j]] != i)
                cout << "(" << i << " " << adjacency[i][j] << ")" << "forward edge" << endl;
            else if (start[i] > start[adjacency[i][j]] && end[i] > end[adjacency[i][j]])
                cout << "(" << i << " " << adjacency[i][j] << ")" << "cross edge" << endl;
            else
            {
                cout << "(" << i << " " << adjacency[i][j] << ")" << "back edge" << endl;
            }
        }
    }

    return 0;
}
