#include<bits/stdc++.h>
using namespace std;

//left, right, parent
//getmin
//insert
//decreasekey : 
//extractmin : get root, put last node to root, and bubble down (minheapify) the new root value
//delete

class minheapadt
{
public:
	int maxsize;
	int* harr;
	int currentsize;

	minheapadt(int cap){
		currentsize = 0;
		maxsize = cap;
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

		if (currentsize == maxsize)
		{
			cout << "overflow";
			return; 
		}
		
		currentsize++;
		int i = currentsize-1;
		harr[i] = key;

		while(i != 0 && harr[parent(i)] > harr[i]){

			int temp = harr[parent(i)];
			harr[parent(i)] = harr[i];
			harr[i] = temp;

			i = parent(i);
		}

	}

	int getmin(){

		return harr[0];
	}

	void decreasekey(int i, int newval){

		harr[i] = newval;
		while(i != 0 && harr[parent(i)] > harr[i]){

			int temp = harr[parent(i)];
			harr[parent(i)] = harr[i];
			harr[i] = temp;

			i = parent(i);

		}
	}

	void minheapify(int i){

		int l = left(i);
		int r = right(i);

		int smallest = i;
		if (l < currentsize && harr[l] < harr[i])
		{
			smallest = l;
		}
		else if (r < currentsize && harr[r] < harr[smallest])
		{
			smallest = r;
		}
		if (smallest != i)
		{
			int temp = harr[smallest];
			harr[smallest] = harr[i];
			harr[i] = temp;

			minheapify(smallest);
		}
	}

	int extractmin(){

		if (currentsize <= 0)
		{
			return INT_MAX;
		}

		int root = harr[0];
		harr[0] = harr[currentsize-1];
		currentsize--;
		minheapify(0);

		return root;
	}

	void deletekey(int i){

		decreasekey(i, INT_MIN);
		extractmin();
	}

};



int main()
{

	minheapadt minh(6);
	//cout << minh.currentsize;
	
	minh.insert(10);
	minh.insert(20);
	minh.insert(100);
	minh.insert(30);
	minh.insert(1);
	//minh.insert(100);
	//minh.insert(40);

	for (int i = 0; i < minh.maxsize; ++i)
	{
		cout << minh.harr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < minh.maxsize; ++i)
	{
		int temp = minh.extractmin();
		cout << temp << " ";
	}

	return 0;
}