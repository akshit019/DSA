#include <bits/stdc++.h>
using namespace std;

class maxheapadt
{
public:
	
	int *harr;
	int maxsize;
	int heapsize;
	
	//constructor
	maxheapadt(int cap){

		maxsize = cap;
		heapsize = 0;
		harr = new int[maxsize];
	}

	int parent(int i){

		return (i-1)/2;
	}

	int left(int i){

		return (2*i+1);
	}

	int right(int i){

		return (2*i+2);
	}

	void insert(int key){

		if (heapsize > maxsize)
		{
			cout << "overflow";
			return;
		}

		heapsize++;
		int i = heapsize-1;
		harr[i] = key;

		while(i != 0 && harr[parent(i)] < harr[i]){

			int temp = harr[parent(i)];
			harr[parent(i)] = harr[i];
			harr[i] = temp;

			i = parent(i); 
		}
	}

	int getmax(){

		return harr[0];
	}

	void maxheapify(int i){

		int largest = i;
		int l = left(i);
		int r = right(i);

		//if left child is largest than root
		if (l < heapsize && harr[l] > harr[i])
		{
			largest = l;
		}

		//if right child is larger than largest so far
		if (r < heapsize && harr[r] > harr[largest])
		{
			largest = r;
		}

		//if largest is not root
		if (largest != i)
		{
			int temp = harr[largest];
			harr[largest] = harr[i];
			harr[i] = temp;

			maxheapify(largest);
		}
	}

	int extractmax(){

		if (heapsize <= 0)
		{
			return -1;
		}

		int root = harr[0];
		harr[0] = harr[heapsize-1];
		heapsize--;

		maxheapify(0); //bubble down the smaller element

		return root;
	}
};

int main()
{
	maxheapadt maxh(6);

	maxh.insert(50);
	maxh.insert(12);
	maxh.insert(1);
	maxh.insert(55);
	maxh.insert(7);
	maxh.insert(2);

	for (int i = 0; i < maxh.maxsize; ++i)
	{
		cout << maxh.harr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < maxh.maxsize; ++i)
	{
		int temp = maxh.extractmax();
		cout << temp << " ";
	}
	return 0;
}