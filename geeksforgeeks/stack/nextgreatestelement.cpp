#include <bits/stdc++.h>
using namespace std;

// 13 ---- -1
// 7  ---- 12
// 6 ---- 12
// 12  ---- -1
// 10 ---- -1

int main()
{
	int n;
	cin >> n;

	stack<int> s;
	vector<int> v;

	for (int i = 0; i < n; ++i)
	{
		int temp2;
		cin >> temp2;
		v.push_back(temp2);
	}

	int first;
	first = v[0];
	//cout << first;

	s.push(first);

	for (int i = 1; i < n; ++i)
	{
		int next;
		next = v[i];

		if (!s.empty())
		{
			if(next > s.top()){
				while(next > s.top()){
					int temp = s.top();
					s.pop();
					cout << temp << " " << next << endl;
					if(s.empty()){
						break;
					}
				}
				cout << next << " pushed" << endl;
				s.push(next);
			}
			else{
				cout << next << " pushed" << endl;
				s.push(next);
			}
		}
	}

	while(!s.empty()){
		int temp1 = s.top();
		s.pop();
		cout << temp1 << " " << "-1" << endl;
	}


	return 0;
}