#include <vector>
#include <iostream>

using namespace std;

vector<int> bellmanFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n + 1, 1e8);
    dist[src] = 0;

    // Apply the relaxation step for n-1 times (number of vertices)
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e8 && (dist[u] + wt < dist[v])) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative cycles
    bool hasNegativeCycle = false;
    for (int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != 1e8 && (dist[u] + wt < dist[v])) {
            hasNegativeCycle = true;
        }
    }

    // If there is a negative cycle, return an empty vector
    if (hasNegativeCycle) {
        return {};
    }

    // Otherwise, return the computed distances
    return dist;
}

int main() {
    // Example usage:
    int n = 5; // Number of vertices
    int m = 8; // Number of edges
    int src = 0; // Source vertex
    vector<vector<int>> edges = {{0, 1, 5}, {0, 2, 4}, {1, 3, 3}, {3, 4, 1}, {4, 1, -6}, {2, 1, 6}, {2, 3, 2}, {3, 2, 7}};

    vector<int> result = bellmanFord(n, m, src, edges);

    if (result.empty()) {
        cout << "Negative cycle detected!" << endl;
    } else {
        cout << "Shortest distances from source " << src << " are: ";
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
