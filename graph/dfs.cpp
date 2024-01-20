#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

void prepareList(unordered_map<int, set<int>> &adjList, const vector<vector<int>> &edges) {
    for (const auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void dfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &component, int node) {
    component.push_back(node);
    visited[node] = true;

    for (const auto &neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(adjList, visited, component, neighbor);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, const vector<vector<int>> &edges) {
    unordered_map<int, set<int>> adjList;
    prepareList(adjList, edges);
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            vector<int> component;
            dfs(adjList, visited, component, i);
            ans.push_back(component);
        }
    }
    return ans;
}

int main() {
    // Example usage:
    int V = 5;  // Number of vertices
    int E = 4;  // Number of edges
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}, {4, 2}};

    vector<vector<int>> components = depthFirstSearch(V, E, edges);

    // Displaying the connected components
    for (const auto &component : components) {
        cout << "Connected Component:";
        for (int node : component) {
            cout << " " << node;
        }
        cout << endl;
    }

    return 0;
}
