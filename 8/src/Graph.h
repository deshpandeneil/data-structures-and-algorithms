/*
 * Graph.h
 *
 *  Created on: 28-Nov-2020
 *      Author: Neil
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include<iostream>

class Graph {
	int V = 0, E = 0;
	int *matrix;
	std::string *vertex_names;
public:
	Graph();

	// graph creation functions

	void create_adj_matrix();

	// graph utility functions

	void display_matrix();

	// functions to find shortest path

	void dijkstras(int);

	virtual ~Graph();
private:

	// more graph utility functions

	int get_node_index(std::string);
};

#endif /* GRAPH_H_ */
