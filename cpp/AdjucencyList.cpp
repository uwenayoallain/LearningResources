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
        for (int i = 0; i < nodes; i++)
            cout << "Node: " + i;
        {
            for (auto V : adjList[i])
            {
                cout << "->" << V;
            }
            cout << endl;
        }
    }
};

int main()
{
    AdjucencyList list(5);
    list.display();
}
