#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node) {
    if (parent[node] == node) {
        return node;
    }
    // Path compression
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[v] < rank[u]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n) {
    sort(edges.begin(), edges.end(), cmp);

    vector<int> rank(n);
    vector<int> parent(n);
    makeSet(parent, rank, n);

    int minWeight = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];
        if (u != v) {
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }

    return minWeight;
}
// TC:O(MlogM) sc O(n)
int main() {
    // Example usage:
    int n = 6;  // Number of vertices
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 4}, {1, 2, 1}, {1, 3, 7}, {2, 4, 3}, {3, 4, 1}, {3, 5, 5}, {4, 5, 2}};

    int minWeight = minimumSpanningTree(edges, n);

    cout << "Minimum Spanning Tree Weight: " << minWeight << endl;

    return 0;
}
