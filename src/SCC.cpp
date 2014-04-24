#include "SCC.h"
#include <stdio.h>

SCC::SCC(char* filename){
	graph = Graph(filename);

	pre_values = new int[graph.get_size()];
	post_values = new int[graph.get_size()];
	visited = new bool[graph.get_size()];

	for (int i = 0; i < graph.get_size(); ++i){
		pre_values[i] = 0;
		post_values[i] = 0;
		visited[i] = false;
	}

	current_value = 0;
}

void SCC::depth_first_search(int start){
	
}

void SCC::display_dfs(){
	for (int i = 0; i < graph.get_size(); ++i){
		printf("%d: %d, %d\n", (i + 1), pre_values[i], post_values[i]);
	}
}