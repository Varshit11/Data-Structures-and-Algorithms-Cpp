/* C++ program to implement bellman ford algorithm */

#include<bits/stdc++.h>
using namespace std;

struct Edge{
	int source, dest, weight;
};

struct Graph{
	int V, E;
	struct Edge* edge;
};

Graph* create_graph(int V, int E){
	struct Graph* graph = new Graph;
	graph->E = E;
	graph->V = V;
	graph->edge = new Edge[E];
	return graph;
}

void print_distance(int dist[], int V){
	for(int i = 0; i<V; i++) cout<<"Vertex: "<<i<<" Distance is "<<dist[i]<<endl;
}

void bellman_ford(struct Graph* graph, int source){
	int V = graph->V;
	int E = graph->E;
	int dist[V];
	for(int i = 0; i<V; i++) dist[i] = INT_MAX;
	dist[source] = 0;
	
	for(int i = 1; i<=V-1; i++){
		for(int j = 0; j<E; j++){
			int u = graph->edge[j].source;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if(dist[u] != INT_MAX && dist[v] > dist[u] + weight) dist[v] = dist[u] + weight;
		}
	}
	
	// now finding if there exisits any negative cycles
	for(int i = 0; i<E; i++){
		int u = graph->edge[i].source;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if(dist[u] != INT_MAX && dist[v] > dist[u] + weight){
			cout<<"The graph contains negative weight cycle "<<endl;
			return;
		}
	}
	
	print_distance(dist, V);
	return;
}

int main() 
{ 
    int V = 5;
    int E = 8;
    struct Graph* graph = create_graph(V, E); 
	
    graph->edge[0].source = 0; 
    graph->edge[0].dest = 1; 
    graph->edge[0].weight = -1; 

    graph->edge[1].source = 0; 
    graph->edge[1].dest = 2; 
    graph->edge[1].weight = 4; 

    graph->edge[2].source = 1; 
    graph->edge[2].dest = 2; 
    graph->edge[2].weight = 3; 
  
    graph->edge[3].source = 1; 
    graph->edge[3].dest = 3; 
    graph->edge[3].weight = 2; 

    graph->edge[4].source = 1; 
    graph->edge[4].dest = 4; 
    graph->edge[4].weight = 2; 

    graph->edge[5].source = 3; 
    graph->edge[5].dest = 2; 
    graph->edge[5].weight = 5; 

    graph->edge[6].source = 3; 
    graph->edge[6].dest = 1; 
    graph->edge[6].weight = 1; 

    graph->edge[7].source = 4; 
    graph->edge[7].dest = 3; 
    graph->edge[7].weight = -3; 
  
    bellman_ford(graph, 0); 
  
    return 0; 
} 

