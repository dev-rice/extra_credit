#include "Graph.h"
#include "SCC.h"
#include <stdio.h>

int main(){

	SCC scc("graph.txt");
	scc.run_algorithm(5);
	
}