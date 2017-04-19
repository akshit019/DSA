#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
bool visited[100];


int bfs(int root){

	queue<int> q;
	q.push(root);
	visited[root] = true;
	int m = 1;

	while(!q.empty()){

		int s = q.size();
		m = max(m, s);
		int a = q.front();
		q.pop();
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
				q.push(adj[a][i]);
			}
		}
	}

	return m;

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

void dfsrecursive(int node){

	if (!visited[node])
	{
		visited[node] = true;
		cout << node << " ";

		for (int i = adj[node].size()-1; i >= 0; --i)
		{
			dfsrecursive(adj[node][i]);
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
		// adj[b].push_back(a);
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

	// int m1 = bfs(2);
	// cout << endl << m1;

	dfs(2);
	cout << endl;
	for (int i = 0; i < v; ++i)
	{
		cout << dist[i] << " ";
	}
	// dfsrecursive(2);


	return 0;
}