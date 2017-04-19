#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int v; // no of vertices
	list<int> *adj; // pointer to an array of adjacency lists 
public:

	Graph(int v){
		this->v = v;
		adj = new list<int>[v];
	}

	void addedge(int v, int u){

		adj[v].push_back(u); // add u to v's list
	}

	void BFS(int s){

		//marking all vertices as non visited
		bool *visited = new bool[v];
		for (int i = 0; i < v; ++i)
		{
			visited[i] = false;
		}

		// create queue for BFS
		list<int> queue;

		// mark current node as visited and enqueue it
		visited[s] = true;
		queue.push_back(s);

		// it  will be used to get all the adjacent vertices of a vertex
		list<int>::iterator it;

		while(!queue.empty()){

			s = queue.front();
			cout << s << " ";
			queue.pop_front();

			// getting all the adjacent vertices of s, if not visited, mark them visited and enqueue it
			for (it = adj[s].begin(); it != adj[s].end(); ++it)
			 {
			 	if (!visited[*it])
			 	{
			 		visited[*it] = true;
			 		queue.push_back(*it);
			 	}
			 } 
		} 
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

    g.BFS(2);

	return 0;
}