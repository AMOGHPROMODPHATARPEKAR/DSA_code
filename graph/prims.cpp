#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <climits>

using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < m; i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // Start algorithm from node 1
    key[1] = 0;

    for (int i = 1; i <= n; i++) {
        int mini = INT_MAX;
        int u;  // Min index

        // Find the minimum key value node not yet included in MST
        for (int v = 1; v <= n; v++) {
            if (mst[v] == false && key[v] < mini) {
                mini = key[v];
                u = v;
            }
        }

        // Mark the min node as true (included in MST)
        mst[u] = true;

        // Check for adjacent nodes of the min node
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    // Create the MST edges
    vector<pair<pair<int, int>, int>> ans;
    for (int i = 2; i <= n; i++) {
        ans.push_back({{parent[i], i}, key[i]});
    }
    return ans;
}

int main() {
    // Example usage:
    int n = 5;  // Number of vertices
    int m = 7;  // Number of edges
    vector<pair<pair<int, int>, int>> edges = {
        {{1, 2}, 1}, {{1, 3}, 2}, {{2, 3}, 3}, {{2, 4}, 1}, {{3, 4}, 4}, {{4, 5}, 2}, {{3, 5}, 3}};

    vector<pair<pair<int, int>, int>> mstEdges = calculatePrimsMST(n, m, edges);

    cout << "Minimum Spanning Tree Edges:\n";
    for (auto edge : mstEdges) {
        cout << "Edge {" << edge.first.first << " - " << edge.first.second << "} with weight " << edge.second << endl;
    }

    return 0;
}
