#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

void dfs(int node, int parent, int &timer, unordered_map<int, bool> &visited,
         unordered_map<int, list<int>> &adj, vector<int> &disc, vector<int> &low,
         vector<vector<int>> &result) {
    visited[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node]) {
        if (nbr == parent) {
            continue;
        }
        if (!visited[nbr]) {
            dfs(nbr, node, timer, visited, adj, disc, low, result);
            low[node] = min(low[node], low[nbr]);

            // Check for bridge
            if (low[nbr] > disc[node]) {
                result.push_back({node, nbr});
            }
        } else {
            // Back edge is present
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
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
    vector<vector<int>> result;

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
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};

    vector<vector<int>> bridges = findBridges(edges, v, e);

    cout << "Bridges in the graph:\n";
    for (const auto &bridge : bridges) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
}
