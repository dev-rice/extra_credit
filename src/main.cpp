#include "Graph.h"
#include "SCC.h"
#include <stdio.h>

int main(){
	
	Graph graph("graph.txt");
	graph.display();

	printf("\n");

	SCC scc("graph.txt");
	scc.depth_first_search(1);
	scc.display_dfs();
	
}