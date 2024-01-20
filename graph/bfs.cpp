#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

void prepareList(unordered_map<int, set<int>> &adjList, vector<vector<int>> edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        // Traverse all neighbors of front node
        for (auto i : adjList[frontNode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void printAdjList(unordered_map<int, set<int>> adj) {
    for (auto i : adj) {
        cout << i.first << "->";
        for (auto j : i.second) {
            cout << j << ",";
        }
        cout << endl;
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {
    unordered_map<int, set<int>> adjList;
    prepareList(adjList, adj);
    printAdjList(adjList);

    vector<int> ans;
    unordered_map<int, bool> visited;

    // Check for all components as we can have disconnected components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

int main() {
    // Example usage
    int n = 8;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 7}, {2, 5},{3,6}};

    vector<int> result = bfsTraversal(n, edges);

    // Displaying the result
    cout << "BFS Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
