#include <iostream>

using namespace std;

class AdjucencyMatrix
{
private:
    int nodes;
    int **matrix;

public:
    AdjucencyMatrix(int nodes)
    {
        this->nodes = nodes;
        matrix = new int *[nodes];
        for (int i = 0; i < nodes; i++)
        {
            matrix[i] = new int[nodes];
        }
    }

    void display()
    {
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void addEdge(int orgin, int destination)
    {
        if (orgin < 0 || destination < 0 || orgin >= nodes || destination >= nodes)
        {
            cout << "Invalid Input" << endl;
            return;
        }
        matrix[orgin][destination] = 1;
    }
}

int
main()
{
    AdjucencyMatrix matrix(5);
    matrix.display();
    return 0;
}