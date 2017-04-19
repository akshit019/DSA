#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int v;
	list<int> *adj;

public:
	Graph(int v){
		this->v = v;
		adj = new list<int>[v];
	}

	void addedge(int w, int u){

		adj[w].push_back(u); // add u to w's list
	}

	void DFSUtil(int s, bool visited[]){

		//marking current node as visited abd print it
		visited[s] = true;
		cout << s << " ";

		//recur all vertices adjacent to this vertex
		list<int>::iterator it;

		for (it = adj[s].begin(); it != adj[s].end(); ++it)
		{
			if (!visited[*it])
			{
				DFSUtil(*it, visited);
			}
		}
	}

	void DFS(int s){

		//mark all vertices as non visited
		bool *visited = new bool[v];
		for (int i = 0; i < v; ++i)
		{
			visited[i] = false;
		}

		//call DFSUtil
		DFSUtil(s, visited);

	}
	
};


int main()
{

    Graph g(4);

    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);

    g.DFS(2);

}