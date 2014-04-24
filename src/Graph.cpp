#include "Graph.h"
#include <stdio.h>

Graph::Graph(char* filename){
	load_graph(filename);
}

void Graph::construct_graph(int nodes){
	graph = new int*[nodes];
	for (int i = 0; i < nodes; ++i){
		graph[i] = new int[nodes];
		for (int j = 0; j < nodes; ++j){
			//Not ideal for some other algorthims but
			// it is okay for SCCs, Dijkstra's, and Prim's
			graph[i][j] = 0;
		}
	}
}

void Graph::load_graph(char* filename){
	FILE* file;
	file = fopen(filename, "r");

	if (file == NULL){
		fprintf(stderr, "Cannot open graph file!\n");
		return;
	}

	int edges;
	fscanf(file, "%d %d", &nodes, &edges);

	construct_graph(nodes);

	int from, to, weight;

	while (fscanf(file, "%d %d %d", &from, &to, &weight) != EOF){
		graph[from-1][to-1] = weight;
	}	

	fclose(file);

	return;
}

void Graph::reverse(){
	int** to_reverse = new int*[nodes];
	for (int i = 0; i < nodes; ++i){
		to_reverse[i] = new int[nodes];
	}

	for (int i = 0; i < nodes; ++i){
		for (int j = 0; j < nodes; ++j){
			to_reverse[j][i] = graph[i][j];
		}
	}

	graph = to_reverse;

	to_reverse = NULL;
	delete to_reverse;
}

int Graph::get_edge_weight(int from, int to){
	return graph[from - 1][to - 1];
}

void Graph::display(){

	for (int i = 0; i < nodes; ++i){
		for (int j = 0; j < nodes; ++j){
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}

