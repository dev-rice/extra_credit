#ifndef SCC_h
#define SCC_h

#include "Graph.h"

class SCC {
public:
	SCC(char*);

	void depth_first_search(int);
	void display_dfs();
private:
	
	Graph graph;

	int* pre_values;
	int* post_values;
	bool* visited;

	int current_value;
};

#endif