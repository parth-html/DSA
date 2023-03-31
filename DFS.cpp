#include <bits/stdc++.h>
using namespace std;

class DFS
{
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, bool> isVisited;
    vector<int> ans;
    int lastVisited;

    void createGraph(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (!direction)
        {
            adj[v].push_back(u);
        }
    }

    void TraverseDFS(int start)
    {
        isVisited[start] = true;
        ans.push_back(start);
        for (auto i : adj[start])
        {
            if (!isVisited[i])
            {
                TraverseDFS(i);
            }
        }
    }

    void printDFS()
    {
        for (auto i : ans)
        {
            cout << i << " ";
        }
    }
};

int main()
{
    DFS graph;

    graph.createGraph(0, 1, 0);
    graph.createGraph(0, 2, 0);
    graph.createGraph(1, 3, 0);
    graph.createGraph(1, 4, 0);
    graph.createGraph(2, 3, 0);
    graph.createGraph(3, 4, 0);
    graph.createGraph(4, 5, 0);

    for (auto i : graph.adj)
        {
            if (!graph.isVisited[i.first])
            {
                graph.TraverseDFS(i.first);
            }
        }
    graph.printDFS();
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
