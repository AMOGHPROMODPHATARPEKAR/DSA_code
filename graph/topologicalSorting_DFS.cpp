#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>

using namespace std;

void topoDfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, stack<int> &st) {
    visited[node] = true;

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            topoDfs(neighbor, visited, adj, st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    unordered_map<int, bool> visited;
    stack<int> st;

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            topoDfs(i, visited, adj, st);
        }
    }
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main() {
    // Example usage:
    int v = 6;  // Number of vertices
    int e = 6;  // Number of edges
    vector<vector<int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

    vector<int> sortedOrder = topologicalSort(edges, v, e);

    cout << "Topological Order: ";
    for (int node : sortedOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
