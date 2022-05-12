#include <iostream>
#include <vector>

using namespace std;

class AdjucencyList
{
private:
    int nodes;
    vector<int> *adjList;

public:
    AdjucencyList(int nodes)
    {
        this->nodes = nodes;
        adjList = new vector<int>(nodes);
    }
    void display()
    {
        for (int i = 0; i <= nodes; i++)
        {
            for (auto V: adjList[i])
            {
                cout << "->" << V;
            }
            cout << endl;
        }
    }

    void addEdge(int orgin, int destination)
    {
        adjList[orgin].push_back(destination);
        adjList[destination].push_back(orgin);
    }
    void deleteEdge(int orgin, int destination)
    {
        for (int i = 0; i < adjList[destination].size(); i++)
        {
            if (adjList[destination][i] == orgin)
            {
                adjList[destination].erase(adjList[destination].begin() + i);
            }
        }
        // adjList[orgin].erase(find(adjList[orgin].begin(), adjList[orgin].end(), destination));
    }
};

int main()
{
    AdjucencyList list(5);
    list.addEdge(0, 1);
    list.addEdge(1, 1);
    list.display();
    return 0;
}