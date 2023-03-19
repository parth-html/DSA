#include <bits/stdc++.h>
using namespace std;

class BFS
{
public:
    unordered_map<int, vector<int>> adj;

    void createGraph(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (!direction)
        {
            adj[v].push_back(u);
        }
    }

    void printBFS(int start)
    {
        vector<int> ans;
        unordered_map<int, bool> visited;

        queue<int> q;
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

        for (auto i : ans)
        {
            cout << i << ", ";
        }
    }

    void printGraph()
    {
        for (auto i : adj)
        {
            cout << i.first << "-->";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
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

    // graph.printGraph();
    graph.printBFS(0);
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
