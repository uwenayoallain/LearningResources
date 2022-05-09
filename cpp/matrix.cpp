#include <iostream>

using namespace std;

class AdjucencyMatrix
{
private:
    int **matrix;
    int nodes;

public:
    AdjucencyMatrix(int nodes)
    {
        this.nodes = nodes;
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
}

int
main()
{
    AdjucencyMatrix matrix(5);
    matrix.display();
    return 0;
}