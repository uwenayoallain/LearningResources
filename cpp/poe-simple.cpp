#include <iostream>
using namespace std;

int equilibrium(int arr[], int n)
{
	if(n>3){
		return -1;
	}
	int leftIndex = 0;
	int rightIndex = n-1;
	int idx;
	int lsum=arr[leftIndex];
	int rsum=arr[rightIndex];
	for (int i = 0; i < n; i++)
	{	
	if(lsum<rsum){
		leftIndex++;
		lsum += arr[leftIndex];
		idx = leftIndex+1;
	}else{
		rightIndex--;
		rsum +=arr[rightIndex];
		idx = rightIndex-1;
	}
	}
	if(lsum == rsum){
		return idx;
	}
	return -1;
}

int main()
{
	int arr[] = {2,3,5,5};
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	cout << equilibrium(arr, arr_size);
	return 0;
}

