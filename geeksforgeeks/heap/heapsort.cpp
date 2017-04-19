#include <bits/stdc++.h>
using namespace std;

void maxheapify(int arr[], int n, int i){

	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;

	if (l < n && arr[l] > arr[largest])
	{
		largest = l;
	}

	if (r  < n && arr[r] > arr[largest])
	{
		largest = r;
	}

	if (largest != i)
	{
		int temp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;

		maxheapify(arr, n, largest);
	}
}

int heapsort(int arr[], int n){

	// to build a heap from an array, call maxheapify n/2-1 to 0 times. Overall running time O(nlogn)
	for (int i = n/2 - 1; i >= 0; --i)
	{
		maxheapify(arr, n, i);
	}

	for (int i = n-1; i >= 0; --i)
	{

		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		maxheapify(arr, i, 0);
	}


}

int main()
{
	int n = 6;
	int arr[6] = {11, 0, 37, 25, 1, 15};

	heapsort(arr, n);

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}

	return 0;
}