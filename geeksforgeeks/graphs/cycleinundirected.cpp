#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
bool visited[100];

bool iscycleutil(int s, int parent){

	visited[s] = true;

	for (int i = 0; i < adj[s].size(); ++i)
	{
		if (!visited[i])
		{
			if (iscycleutil(adj[s][i], s))
			{
				return true;
			}
		}

		else if (adj[s][i] != parent)
		{
			return true;
		}

	}

	return false;
}

bool iscycle(){

	for (int i = 0; i < 5; ++i)
	{
		visited[i] = false;
	}

	for (int i = 0; i < 5; ++i)
	{
		if (visited[i])
		{
			continue;
		}
		else
		{
			if (iscycleutil(i, -1))
			{
				return true;
			}
		}
	}

	return false;
}

void dfs(int root){

	stack<int> s;
	s.push(root);
	visited[root] = true;

	while(!s.empty()){

		int a = s.top();
		s.pop();
		cout << a << " ";

		for (int i = 0; i < adj[a].size(); ++i)
		{
			if (visited[adj[a][i]])
			{
				continue;
			}
			else
			{
				visited[adj[a][i]] = true;
				s.push(adj[a][i]);
			}
		}
	}
}

int main()
{
	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; ++i)
	{
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	//print graph
	for (int i = 0; i < v; ++i)
	{
		cout << i << " =";

		for (int j = 0; j < adj[i].size(); ++j)
		{
			cout << adj[i][j] << " ";
		}

		cout << endl;
	}


	//dfs(2);
	bool b = iscycle();
	cout << b;

	return 0;
}