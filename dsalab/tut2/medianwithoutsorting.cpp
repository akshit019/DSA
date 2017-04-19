#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};

	priority_queue<int> pql;
	//priority_queue<int> pqr;
	priority_queue<int, vector<int>, greater<int> > pqr;

	int mid = arr[0];

	for (int i = 1; i < 5; ++i)
	{

		if (arr[i] < mid)
		{
			if (pql.size() == pqr.size())
			{
				pql.push(arr[i]);
			}
			else if (abs(pql.size()-pqr.size()) == 1)
			{
				pqr.push(mid);
				mid = pql.top();
				pql.pop();
				pql.push(arr[i]);
			}
		}

		else if (arr[i] > mid)
		{
			// for (int j = 0; j < pql.size(); ++j)
			// {
			// 	cout << pql.top() << " ";
			// 	pql.pop();
			// }
			// cout << ".";
			// for (int j = 0; j < pqr.size(); ++j)
			// {
			// 	cout << pqr.top() << " ";
			// 	pqr.pop();
			// }

			if (pql.size() == pqr.size())
			{
				pqr.push(arr[i]);
			}
			else if (abs(pql.size()-pqr.size()) == 1)
			{
				pql.push(mid);
				mid = pqr.top();
				pqr.pop();
				pqr.push(arr[i]);
			}		
		}


	}

	cout << mid;
	return 0;
}