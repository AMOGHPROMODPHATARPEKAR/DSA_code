#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t) {
    // Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto neighbor : adj[front]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = front;
                q.push(neighbor);
            }
        }
    }

    // Reconstruct the shortest path
    vector<int> ans;
    int cur = t;
    ans.push_back(t);

    while (cur != s) {
        cur = parent[cur];
        ans.push_back(cur);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    // Example usage:
    int n = 6;  // Number of vertices
    int m = 7;  // Number of edges
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 5}, {4, 6}, {5, 6}};
    int source = 1;
    int target = 6;

    vector<int> shortestPathResult = shortestPath(edges, n, m, source, target);

    cout << "Shortest Path from " << source << " to " << target << ": ";
    for (int node : shortestPathResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
