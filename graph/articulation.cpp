#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

void dfs(int node, int parent, int &timer, unordered_map<int, bool> &visited,
         unordered_map<int, list<int>> &adj, vector<int> &disc, vector<int> &low,
         vector<bool> &result) {
    visited[node] = true;
    disc[node] = low[node] = timer++;
    int child=0;
    for (auto nbr : adj[node]) {
        if (nbr == parent) {
            continue;
        }
        if (!visited[nbr]) {
            dfs(nbr, node, timer, visited, adj, disc, low, result);
            low[node] = min(low[node], low[nbr]);

            // Check for AP
            if (low[nbr]>= disc[node] && parent !=-1) {
                result[node]=true;
            }
            child++;
        } else {
            // Back edge is present
            low[node] = min(low[node], disc[nbr]);
        }
    }
    if(parent ==-1 && child >1)
    {
        result[node]=1;
    }
}

vector<bool> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;

    unordered_map<int, bool> visited;
    int timer = 0;
    vector<bool> result(v);

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i, parent, timer, visited, adj, disc, low, result);
        }
    }

    return result;
}

int main() {
    // Example usage:
    int v = 5;  // Number of vertices
    int e = 5;  // Number of edges
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {0, 3}, {3, 4}};

    vector<bool> arti = findBridges(edges, v, e);

    cout << "artculation point in the graph:\n";
    for(int i=0;i<arti.size();i++)
    {
        if(arti[i] == true)
        {
            cout<<i<<" ";
        }
    }

    return 0;
}
