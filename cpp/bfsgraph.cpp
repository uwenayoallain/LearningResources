#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

class Graph
{
private:
    int V;
    std::vector<std::list<int>> adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int s);
    void BFS(int s);
    void DFSUtil(int s, std::vector<bool> &visited);
    void printGraph();
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    std::vector<bool> visited(V, false);
    std::list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    while (!queue.empty())
    {
        s = queue.front();
        std::cout << s << " ";
        queue.pop_front();
        for (auto i : adj[s])
        {
            if (!visited[i])
            {
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }
}

void Graph::DFS(int s)
{
    std::vector<bool> visited(V, false);
    DFSUtil(s, visited);
}

void Graph::DFSUtil(int s, std::vector<bool> &visited)
{
    visited[s] = true;
    std::cout << s << " ";
    for (auto i : adj[s])
    {
        if (!visited[i])
            Graph::DFSUtil(i, visited);
    }
}

void Graph::printGraph()
{
    for (int i = 0; i < V; i++)
    {
        std::cout << "Adjacency list of vertex " << i << ": ";
        for (auto j : adj[i])
            std::cout << j << " ";
        std::cout << std::endl;
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.printGraph();
    std::cout << std::endl;
    g.BFS(2);
    std::cout << std::endl;
    // g.DFS(2);
    return 0;
}
