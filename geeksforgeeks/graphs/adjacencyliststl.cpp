#include <bits/stdc++.h>
using namespace std;

//array of vectors
void addedge(vector<int> adj[], int u, int v){

	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printgraph(vector<int> adj[], int v){

	for (int i = 0; i < v; ++i)
	{	
		cout << i << " = ";

		for (int j = 0; j < adj[i].size(); ++j)
		{
			cout << adj[i][j] << " ";
		}

		cout << endl;
	}

}

int main()
{
	int v = 5;
	vector<int> adj[v];
	addedge(adj, 0, 1);
	addedge(adj, 0, 4);
    addedge(adj, 1, 2);
    addedge(adj, 1, 3);
    addedge(adj, 1, 4);
    addedge(adj, 2, 3);
    addedge(adj, 3, 4);

    printgraph(adj, v);

	return 0;
}