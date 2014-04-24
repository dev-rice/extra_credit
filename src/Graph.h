#ifndef Graph_h
#define Graph_h

class Graph {
public:
	Graph() {;}
	Graph(char*);

	void load_graph(char*);
	void reverse();
	void display();

	int get_edge_weight(int, int);
	int get_size() { return nodes; }

private:
	void construct_graph(int);
	
	int** graph;
	int nodes;
};

#endif