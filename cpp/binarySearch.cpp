#include <iostream>

using namespace std;

// it is used on sorted array
int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        return -1;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Enter the key to be searched: ";
    cin >> key;
    int result = binarySearch(arr, n, key);
    if (result == -1)
    {
        cout << "Element [" << key << "] not found";
    }
    else
    {
        cout << "Element [" << key << "] found at position " << result + 1;
    }
    return 0;
}