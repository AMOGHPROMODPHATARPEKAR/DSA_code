#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>

using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, stack<int> &s) {
    visited[node] = true;

    for (auto nbr : adj[node]) {
        if (!visited[nbr]) {
            dfs(nbr, visited, adj, s);
        }
    }
    s.push(node);
}

void revDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj) {
    visited[node] = true;

    for (auto nbr : adj[node]) {
        if (!visited[nbr]) {
            revDFS(nbr, visited, adj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    stack<int> s;

    // Create topological sort
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj, s);
        }
    }

    // Create transpose graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        for (auto nbr : adj[i]) {
            transpose[nbr].push_back(i);
        }
    }

    // DFS calling on topological order
    int count = 0;
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        if (!visited[top]) {
            count++;
            revDFS(top, visited, transpose);
        }
    }

    return count;
}

int main() {
    // Example usage:
    int v = 5;  // Number of vertices
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};

    int SCCCount = stronglyConnectedComponents(v, edges);

    cout << "Number of Strongly Connected Components: " << SCCCount << endl;

    return 0;
}
