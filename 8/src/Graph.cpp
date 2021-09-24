/*
 * Graph.cpp
 *
 *  Created on: 28-Nov-2020
 *      Author: Neil
 */

#include "Graph.h"
#include<iostream>
#include<limits.h>

Graph::Graph() {
	// TODO Auto-generated constructor stub
	do{
		std::cout << "\nEnter the number of vertices	: ";
		std::cin >> V; // take the size of graph from user
		if(!std::cin.good()){ // loop till correct data type is not entered
			std::cout << "\nPlease enter correct data type\n";
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		std::cout << "\nEnter the number of edges: ";
		std::cin >> E;
		if(!std::cin.good()){ // loop till correct data type is not entered
			std::cout << "\nPlease enter correct data type\n";
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		break;
	}while(true);

	matrix = new int [V * V]; // allocate n*n space for array (used in prims algo)
	vertex_names = new std::string [V]; // allocate memory to store node names

	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			matrix[i * V + j] = 0; // initialize all elements of matrix to 0
		}
	}

	std::cout << "\n";
	for(int j = 0; j < V; j++){
		std::cout << "\nEnter name of vertex " << j << ": "; // ask user to name all nodes
		if(j == 0)
			std::cin.ignore();
		std::getline(std::cin, vertex_names[j], '\n'); // store node names in separate array
	}
}

// utility function to get index of a node
// this is required since user adds edges using node names and not indexes
int Graph::get_node_index(std::string name){
	for(int i = 0; i < V; i++){
		if(vertex_names[i] == name)
			return i;
	}
	return -1;
}

void Graph::create_adj_matrix(){
	std::string a, b;
	int w;
	for(int i = 0; i < E; i++){ // loop till we get values for all edges
		std::cout << "\nEnter name of source vertex: ";
		std::getline(std::cin, a, '\n');
		int u = get_node_index(a); // check if this node exists
		if(u == -1){
			std::cout << "\nNo edge called " << a << " exists\n";
			return;
		}
		std::cout << "\nEnter name of destination vertex: ";
		std::getline(std::cin, b, '\n');
		int v = get_node_index(b); // check if this node exists
		if(v == -1){
			std::cout << "\nNo edge called " << b << " exists\n";
			return;
		}
		do{
			std::cout << "\nEnter weight of edge: ";
			std::cin >> w;
			if(!std::cin.good()){ // loop till correct data type is not entered
				std::cout << "\nPlease enter valid data type\n";
				std::cin.clear();
				std::cin.ignore();
				continue;
			}
			break;
		}while(true);
		matrix[u * V + v] = w; // set value to edge in matrix
		matrix[v * V + u] = w; // if we set value to (u, v) then (v, u) must also have the same value
		std::cin.ignore();
	}
}

void Graph::display_matrix(){
	std::cout << "\n\nGRAPH IS:\n\n";
	for(int k = 0; k < V; k++){ // for the column
		std::cout << "\t" << vertex_names[k];
	}
	std::cout << "\n=============================================\n";
	for(int i = 0; i < V; i++){ // print row wise
		std::cout << vertex_names[i] << " | ";
		for(int j = 0; j < V; j++){
			std::cout << "\t" << matrix[i * V + j]; // display weight of edge going from i to j
		}
		std::cout << "\n";
	}
}

void Graph::dijkstras(int start){
	bool visited[V];
	int distance[V], previous[V], min_cost;

	std::cout << "\nINITIALIZING UTILITY ARRAYS...\n";

	for(int i = 0; i < V; i++){
		visited[i] = false;
		if(matrix[start * V + i] != 0)
			distance[i] = matrix[start * V + i];
		else
			distance[i] = INT_MAX; // set all distances to max
		previous[i] = -1;
	}

	int current = start; // set start node
	int total_visited = 0;
	visited[current] = true;
	distance[start] = 0;

	std::cout << "\nStart node set to " << start << "\n";

	while(total_visited != V){
		min_cost = INT_MAX;

		std::cout << "\nVisiting all nodes...\n";

		for(int j = 0; j < V; j++){
			std::cout << "\nChecking if node is already visited and distance of node...\n";
			if(visited[j] == false && distance[j] <= min_cost){ // check if distance is less than min
				min_cost = distance[j]; // update min
				current = j; // go to next node
			}
		}

		visited[current] = true;
		total_visited++;

		for(int k = 0; k < V; k++){
			if(!visited[k] && matrix[current * V + k] && distance[current] != INT_MAX && distance[current] +  matrix[current * V + k] < distance[k]){
				distance[k] = distance[current] + matrix[current * V + k]; // update distance of current node from source
				previous[k] = current; // set prev node
			}
		}
	}
	// displaying shortest path to each vertex
	printf("Vertex\t Distance\t\tPath");
	int j = 0;
	for (int i = 0; i < V; i++){
		printf("\n%d -> %d \t\t %d\t\t%d ",
		start, i, distance[i], i); // formatting of output
		j = i;
		do{ // print parents of all vertices till start node is crossed
			j = previous[j];
			if(j != -1 && j != i)
				std::cout << " <- " << j;
		} while(previous[j] != -1);
		std::cout << " <- " << start;
	}
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

