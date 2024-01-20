#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <set>
#include <climits>

using namespace std;
//APPliacable for only positive weight 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Initialize distance array
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    // Minimum distance set (pair: <distance, node>)
    set<pair<int, int>> s;
    s.insert(make_pair(0, source));

    while (!s.empty()) {
        auto top = *(s.begin());

        int nodeDist = top.first;
        int node = top.second;

        // Remove the top record
        s.erase(s.begin());

        // Traverse neighbors
        for (auto i : adj[node]) {
            if (nodeDist + i.second < dist[i.first]) {
                // Check if the record is in the set
                auto record = s.find(make_pair(dist[i.first], i.first));
                // Found, erase it
                if (record != s.end()) {
                    s.erase(record);
                }
                // Update distance
                dist[i.first] = nodeDist + i.second;
                // Insert updated record
                s.insert(make_pair(dist[i.first], i.first));
            }
        }
    }
    return dist;
}

int main() {
    // Example usage:
    int vertices = 3;
    int edges = 3;
    vector<vector<int>> vec = {{0, 1, 2}, {0, 2, 4}, {1, 2, 1}, {1, 3, 7}, {2, 4, 3}, {3, 4, 1}, {3, 5, 5}, {4, 5, 2}, {5, 0, 1}};
//    vector<vector<int>>vec ={{0,1,5},{0,2,6},{1,2,3}};
    int source = 0;

    vector<int> shortestDistances = dijkstra(vec, vertices, edges, source);

    cout << "Shortest Distances from source " << source << " to all other nodes:\n";
    for (int i = 0; i < vertices; i++) {
        cout << "Node " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
