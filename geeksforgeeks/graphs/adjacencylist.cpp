#include <bits/stdc++.h>
using namespace std;

//adjacency list node
struct AdjListNode
{
	int dest;
	AdjListNode* next;
};

//adjacency list
struct AjdList
{
	AdjListNode* head; //pointer to head node of list
};

//graph is an array of ajacency lists
struct Graph
{
	int v;
	AjdList* array;
};

//create new adjacency list node
AdjListNode* newAdjListNode(int dest){

	AdjListNode* n = new AdjListNode();
	n->dest = dest;
	n->next = NULL;

	return n;
}

Graph* creategraph(int v){

	Graph* g = new Graph();
	g->v = v;
	g->array = new AjdList();

	for (int i = 0; i < v; ++i)
	{
		g->array[i].head = NULL; 
	}

	return g;
}

void addEdge(Graph* g, int src, int dest){

	AdjListNode* n1 = newAdjListNode(dest);
	n1->next = g->array[src].head;
	g->array[src].head = n1;

	//undirected graph, so node from dest to source also
	n1 = newAdjListNode(src);
	n1->next = g->array[dest].head;
	g->array[dest].head = n1;

}

void printGraph(Graph* graph)
{
    for (int i = 0; i < graph->v; ++i)
    {
        AdjListNode* pCrawl = graph->array[i].head;
        printf("\n Adjacency list of vertex %d\n head ", i);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            //cout << "-> " << pCrawl->dest;
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
 
// Driver program to test above functions
int main()
{
    // create the graph given in above fugure
    int V = 5;
    Graph* graph = creategraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
 
    // print the adjacency list representation of the above graph
    printGraph(graph);
 
    return 0;
}

