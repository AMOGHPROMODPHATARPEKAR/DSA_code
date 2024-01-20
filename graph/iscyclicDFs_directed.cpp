#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

bool isCyclic(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited) {
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            bool hasCycle = isCyclic(neighbor, adj, visited, dfsVisited);
            if (hasCycle) {
                return true;
            }
        } else if (dfsVisited[neighbor]) {
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bool hasCycle = isCyclic(i, adj, visited, dfsVisited);
            if (hasCycle) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    // Example usage:
    int n = 5;  // Number of vertices
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 2}};

    bool hasCycle = detectCycleInDirectedGraph(n, edges);

    if (hasCycle) {
        cout << "The directed graph contains a cycle." << endl;
    } else {
        cout << "The directed graph does not contain a cycle." << endl;
    }

    return 0;
}
