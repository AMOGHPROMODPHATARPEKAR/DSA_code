#include <bits/stdc++.h> 
using namespace std;

string canFinish(vector<vector<int>>& prerequisites, int n, int m) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++) {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];

        adj[u].push_back(v);
    }

    vector<int> indeg(n + 1);
    for (auto i : adj) {
        for (auto j : i.second) {
            indeg[j]++;
        }
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;

    while (!q.empty()) {
        int front = q.front();
        topo.push_back(front);
        q.pop();

        for (auto nbr : adj[front]) {
            indeg[nbr]--;
            if (indeg[nbr] == 0) {
                q.push(nbr);
            }
        }
    }

    vector<bool> canFinishCourse(n + 1, false);

    for (int i : topo) {
        canFinishCourse[i] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!canFinishCourse[i]) {
            return "No";
        }
    }

    return "Yes";
}

int main() {
    // Example usage:
    int n = 4;  // Number of courses
    int m = 3;  // Number of prerequisites
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}};

    string result = canFinish(prerequisites, n, m);

    cout << "Can finish all courses? " << result << endl;

    return 0;
}
