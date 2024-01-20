#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

bool isCyclicBFS(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, int src) {
    unordered_map<int, int> parent;
    parent[src] = -1;

    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

        // Traverse all neighbors of the front node
        for (auto neighbor : adjList[frontNode]) {
            if (visited[neighbor] == true && neighbor != parent[frontNode]) {
                return true;
            } else if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = frontNode;
            }
        }
    }
    return false;
}

bool isCyclicDFS(int node,int parent,unordered_map<int, list<int>> adjList,unordered_map<int, bool>&visited)
{
    visited[node]=1;

    for(auto neighbour:adjList[node])
    {
        if(!visited[neighbour])
        {
           bool ans = isCyclicDFS(neighbour,node,adjList,visited);
           if(ans)
           return true;
        }
        else if(neighbour != parent)
        {
            return true;
        }
    }      
    return false;
}


string cycleDetection(vector<vector<int>> &edges, int n, int m) {
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    // Check for all components as we can have disconnected components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bool hasCycle = isCyclicBFS(adjList, visited, i); //iscylicDfs(i,-1,adj,visited)
            if (hasCycle) {
                return "Yes";
            }
        }
    }
    return "No";
}



int main() {
    // Example usage:
    int n = 5;  // Number of vertices
    int m = 4;  // Number of edges
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {3, 4}};

    string result = cycleDetection(edges, n, m);

    cout << "Does the graph contain a cycle? " << result << endl;

    return 0;
}
