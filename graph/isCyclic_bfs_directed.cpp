#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include<queue>
using namespace std;

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
 
     //create Adjacent list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++)
    {
      int u=edges[i].first - 1;
      int v=edges[i].second -1;

      adj[u].push_back(v);
    }
    
    //indegree
    vector<int>indeg(n);
    for(auto i:adj)
    {
        for(auto j:i.second)
        {
            indeg[j]++;
        }
    }

    //0 indeg ko queue me push karlo
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(indeg[i] == 0)
        {
            q.push(i);
        }
    }

    //do bfs
    int cnt =0;
    while(!q.empty())
    {
        int front = q.front();
        
        q.pop();
        cnt++;
        for(auto neighbour:adj[front])
        {
            indeg[neighbour]--;
            if(indeg[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    if(cnt == n)
    {
      return false;
    }
    else
    {
      return true;
    }

}

int main() {
    // Example usage:
    int n = 5;  // Number of vertices
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 2}};

    bool hasCycle = detectCycleInDirectedGraph(n, edges);

    if (hasCycle) {
        cout << "The directed graph contains a cycle." << endl;
    } else {
        cout << "The directed graph does not contain a cycle." << endl;
    }

    return 0;
}
