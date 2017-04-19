#include <bits/stdc++.h>
using namespace std;

vector< pair<int, int> > adj[100];
typedef pair<int, int> ipair;

void prims(int v, int src){

	// priority queue to store vertices that are being preprocessed
	// min heap using pq
	// priority_queue <Type, vector<Type>, ComparisonType > min_heap;
	priority_queue< ipair, vector<ipair> , greater<ipair> > pq;

	// dist vector
	vector<int> dist(v, INT_MAX);

	// to store parent array which in turn stores MST
	vector<int> parent(v, -1);

	//to keep track of vertices included in MST
	vector<bool> inmst(v, false);

	// insert source iyself in pq and initialize its dist to 0
	pq.push(make_pair(0, src));
	dist[src] = 0;

	while(!pq.empty())
	{
		//ipair.first = dist
		//ipair.second = vertex
		int a = pq.top().second;
		pq.pop();

		inmst[a] = true;

		for (int i = 0; i < adj[a].size(); ++i)
		{
			int v1 = adj[a][i].first;
			int w1 = adj[a][i].second;

			if (inmst[v1] == false && dist[v1] > w1)
			{
				dist[v1] = w1;
				pq.push(make_pair(dist[v1], v1));
				parent[v1] = a;
			}
		}
	}
	
	for (int i = 0; i < v; ++i)
	{
		cout << i << "  " << parent[i] << endl; 
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

	prims(v,0);

	return 0;
}