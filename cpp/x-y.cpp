#include <iostream>
using namespace std;

int getDifBetweenXandY(int array[], int n)
{
    int sum = 0;
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        // check if array[i] is odd or even
        if (array[i] % 2 == 0)
        {
            // if even, then add to sum
            y += array[i];
        }
        else
        {
            // if odd, then subtract from sum
            x += array[i];
        }
    }
    sum = x - y;
    return sum;
}

int main()
{
    int array[10] = {3, 3, 4, 4};
    int size = sizeof(array) / sizeof(array[0]);
    cout << "X-Y=" << getDifBetweenXandY(array, size) << endl;
    return 0;
}
