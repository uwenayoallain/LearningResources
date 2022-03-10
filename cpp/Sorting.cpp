#include <iostream>

using namespace std;

void merge(int arr[], int begin, int mid, int end)
{
    int sizeofLeft = mid - begin + 1;
    int sizeofRight = end - mid;
    int left[sizeofLeft];
    int right[sizeofRight];
    for (int i = 0; i < sizeofLeft; i++)
    {
        left[i] = arr[begin + i];
    }
    for (int i = 0; i < sizeofRight; i++)
    {
        right[i] = arr[mid + i + 1];
    }
    int i = 0, j = 0, k = begin;
    while (i < sizeofLeft && j < sizeofRight)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < sizeofLeft)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < sizeofRight)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int begin, int end)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2;
        mergeSort(arr, begin, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    int sizeofArr = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, sizeofArr - 1);
    printArray(arr, sizeofArr);
    return 0;
}