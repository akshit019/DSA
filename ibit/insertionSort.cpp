#include<iostream>
#include<vector>
using namespace std;

std::vector<int> insertionSort(vector<int> vec)
{
	int n = vec.size();

	for (int i = 1; i < n; ++i)
	{
		int value = vec[i];
		int hole = i;

		while(hole > 0 && value < vec[hole -1])
		{
			vec[hole] = vec[hole -1];
			hole--;
		}

		vec[hole] = value;
	}

	return vec;
}

int main()
{
	vector<int> v;
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	vector<int> v1;
	v1 = insertionSort(v);

	for (int i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}

	return 0;
}