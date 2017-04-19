#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10];

void toposort(int v){

	//vector of length v, initialized to 0, to store indegrees
	vector<int> indegree(v,0);

	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < adj[i].size(); ++j)
		{
			indegree[adj[i][j]]++;
		}
	}

	// for (int i = 0; i < v; ++i)
	// {
	// 	cout << indegree[i] << " ";

	// }
	// cout << endl;

	//queue to enqueue vertices with indegree = 0
	queue<int> q;

	for (int i = 0; i < v; ++i)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}

	int count = 0;

	//vector to store order
	vector<int> toporder;

	//dequeue vertices from queue and enqueue adjacents if indegree of adjacents become 0;
	while(!q.empty())
	{
		int a = q.front();
		q.pop();
		toporder.push_back(a);

		//visit neighbours of dequeued node and decrease their indegree by 1
		for (int i = 0; i < adj[a].size(); ++i)
		{
			indegree[adj[a][i]]--;

			//if indegree of any neighnour vertex becomes 0, add it to queue
			if (indegree[adj[a][i]] == 0)
			{
				q.push(adj[a][i]);
			}
		}

		count++;
	}

	//check cycle
	if (count != v){

		cout << "cycle exists";
		return;

	}

	//print topological order
	for (int i = 0; i < v; ++i)
	{
		cout << toporder[i] << " ";
	}
}

int main(int argc, char const *argv[])
{
	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; ++i)
	{
		int u, w;
		cin >> u >> w;

		adj[u].push_back(w);
	}

	for (int i = 0; i < v; ++i)
	{
		cout << i << ": ";

		for (int j = 0; j < adj[i].size(); ++j)
		{
			cout << adj[i][j] << " ";

		}

		cout << endl;
	}

	toposort(v);
	return 0;
}