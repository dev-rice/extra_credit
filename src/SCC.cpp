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

void SCC::run_algorithm(int source){
	//Form reverse(G)
	graph.reverse();
	//Do a dfs of reverse(G)
	depth_first_search(source);
	display_dfs();
	
}

void SCC::depth_first_search(int start){
	std::queue<int> to_explore;
	printf("At %d\n", start);
	++current_value;
	
	pre_values[start - 1] = current_value;
	
	visited[start - 1] = true;

	for (int i = 0; i < graph.get_size(); ++i){
		if (graph.get_edge_weight(start, i + 1) != 0){
			to_explore.push(i + 1);
		}
	}

	while (!to_explore.empty()){
		int current_edge = to_explore.front();
		to_explore.pop();

		if (!visited[current_edge - 1]){
			depth_first_search(current_edge);
		}
	}

	++current_value;
	post_values[start - 1] = current_value;
}

void SCC::display_dfs(){
	for (int i = 0; i < graph.get_size(); ++i){
		printf("%d: %d, %d\n", (i + 1), pre_values[i], post_values[i]);
	}
}