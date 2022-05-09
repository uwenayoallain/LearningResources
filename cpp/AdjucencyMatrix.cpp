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
            for (int j = 0; j < nodes; j++)
            {
                matrix[i][j] = 0;
            }
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
    void deleteEdge(int orgin, int destination)
    {
        if (orgin < 0 || destination < 0 || orgin >= nodes || destination >= nodes)
        {
            cout << "Invalid Input" << endl;
            return;
        }
        matrix[orgin][destination] = 0;
    }
};

int
main()
{
    AdjucencyMatrix matrix(5);
    matrix.addEdge(0, 1);
    matrix.addEdge(0, 2);
    matrix.addEdge(1, 2);
    matrix.addEdge(2, 3);
    matrix.addEdge(3, 4);
    matrix.deleteEdge(0, 1);
    matrix.display();

    return 0;
}
