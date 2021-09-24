/*
 * Graph.h
 *
 *  Created on: 28-Nov-2020
 *      Author: Neil
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include<iostream>

struct Edge{ // this structure is used for kruskals algo
	int source, destination, weight;
};

class Graph {
	int V = 0, E = 0;
	int *matrix;
	Edge *edges;
	std::string *vertex_names;
public:
	Graph();

	// graph creation functions

	void create_adj_matrix();
	void delete_edge(std::string, std::string);

	// graph utility functions

	void display_matrix();
	void sort_edges();

	// functions to find minimum spanning tree

	void prims(int);
	void kruskals();

	// functions to find shortest path

	void dijkstras(int);

	virtual ~Graph();
private:

	// more graph utility functions

	int get_node_index(std::string);
};

#endif /* GRAPH_H_ */
