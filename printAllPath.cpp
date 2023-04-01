#include <bits/stdc++.h>
using namespace std;

class DFS
{
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, bool> isVisited;
    vector<int> ans;
    vector<int> path;

    void createGraph(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (!direction)
        {
            adj[v].push_back(u);
        }
    }

    void TraverseDFS(int start, int target)
    {
        isVisited[start] = true;
        ans.push_back(start);

        if (start == target)
        {
            printDFS();
        }
        else
        {
            for (auto i : adj[start])
            {
                if (!isVisited[i])
                {
                    TraverseDFS(i, target);
                }
            }
        }
        ans.pop_back();
        isVisited[start] = false;
    }

    void printDFS()
    {
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
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

    graph.TraverseDFS(0, 5);
    // graph.printDFS();
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
