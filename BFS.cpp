#include <bits/stdc++.h>
using namespace std;

class BFS
{
public:
    unordered_map<int, vector<int>> adj;
    vector<int> ans;
    unordered_map<int, bool> visited;
    queue<int> q;

    void createGraph(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (!direction)
        {
            adj[v].push_back(u);
        }
    }

    void TraverseBFS(int start)
    {

        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            for (auto j : adj[frontNode])
            {
                if (!visited[j])
                {
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
    }

    void printBFS()
    {
        for (auto i : ans)
        {
            cout << i << " ";
        }
    }
};

int main()
{
    BFS graph;

    graph.createGraph(0, 2, 1);
    graph.createGraph(0, 1, 1);
    graph.createGraph(1, 0, 1);
    graph.createGraph(1, 3, 1);
    graph.createGraph(1, 4, 1);
    graph.createGraph(2, 0, 1);
    graph.createGraph(2, 3, 1);
    graph.createGraph(3, 2, 1);
    graph.createGraph(3, 1, 1);
    graph.createGraph(3, 4, 1);
    graph.createGraph(4, 1, 1);
    graph.createGraph(4, 3, 1);
    graph.createGraph(4, 5, 1);
    graph.createGraph(5, 4, 1);

    for (auto i : graph.adj)
    {
        if (!graph.visited[i.first])
        {
            graph.TraverseBFS(i.first);
        }
        // cout<<i.first<<endl;
    }

    graph.printBFS();

    /*
        0----------------1
        |                | \
        |                |   \
        |                |    4--------5
        |                |   /
        |                | /
        2----------------3

    */

    return 0;
}
