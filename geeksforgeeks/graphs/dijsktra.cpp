#include <bits/stdc++.h>
using namespace std;

vector< pair<int, int> > adj[100];
typedef pair<int, int> ipair;

void dijsktra(int v, int src){

	// priority queue to store vertices that are being preprocessed
	// min heap using pq
	// priority_queue <Type, vector<Type>, ComparisonType > min_heap;
	priority_queue< ipair, vector<ipair> , greater<ipair> > pq;

	// dist vector
	vector<int> dist(v, INT_MAX);

	// insert source iyself in pq and initialize its dist to 0
	pq.push(make_pair(0, src));
	dist[src] = 0;

	while(!pq.empty())
	{
		//ipair.first = dist
		//ipair.second = vertex
		int a = pq.top().second;
		pq.pop();

		for (int i = 0; i < adj[a].size(); ++i)
		{
			int v1 = adj[a][i].first;
			int w1 = adj[a][i].second;

			if (dist[v1] > dist[a] + w1)
			{
				dist[v1] = dist[a] + w1;
				pq.push(make_pair(dist[v1], v1));
			}
		}
	}
	
	for (int i = 0; i < v; ++i)
	{
		cout << i << "  " << dist[i] << endl; 
	}


}

int main()
{
	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; ++i)
	{
		int u, w, d;
		cin >> u >> w >> d;

		adj[u].push_back(make_pair(w, d));
		adj[w].push_back(make_pair(u, d));
	}

	for (int i = 0; i < v; ++i)
	{
		cout << i << ": ";

		for (int j = 0; j < adj[i].size(); ++j)
		{
			cout << adj[i][j].first << "," << adj[i][j].second << "; ";
		}

		cout << endl;
	}

	dijsktra(v,0);

	return 0;
}