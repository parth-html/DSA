#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
  unordered_map<int, vector<int>> adj;

  void addEdge(int v, int u, bool direction)
  {
    // direction = 0 -> undirected
    // direction = 1 -> directed

    // create an edge from u to v
    adj[u].push_back(v);

    if (direction == 0)
    {
      adj[v].push_back(u);
    }
  }

  void printAdjList()
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
  int m;
  cout << "Enter the number of edges" << endl;
  cin >> m;

  Graph g;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    g.addEdge(u, v, 0);
  }

  //printing a graph
  g.printAdjList();
}