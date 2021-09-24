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

	edges = new Edge [E]; // array of edges (used in kruskals algo)
	matrix = new int [V * V]; // allocate n*n space for array (used in prims algo)
	vertex_names = new std::string [V]; // allocate memory to store node names

	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			matrix[i * V + j] = 0; // initialize all elements of matrix to 0
		}
	}

	for(int k = 0; k < E; k++){ // initialize all edges to 0
		edges[k].source = 0;
		edges[k].destination = 0;
		edges[k].weight = 0;
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
		edges[i].source = u; // make an entry of the edge in the array
		edges[i].destination = v;
		edges[i].weight = w;
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

void Graph::prims(int start){

	int current, totalVisited;
	bool visited[V]; // to mark visited nodes
	int previous[V], cost[V], minCost; // to track previous nodes and cost of nodes

	std::cout << "\nInitializing utility arrays and variables...\n";

	for (int i = 0 ; i < V ; i++){
		visited[i] = 0;
		previous[i] = 0;
		cost[i] = INT_MAX;
	}

	current = start; // set current node as start node
	totalVisited = 1;
	visited[current] = 1;
	cost[current] = 0;

	std::cout << "\nCurrent Node: " << start;

	while(totalVisited != V){
		minCost = INT_MAX; // set min cost to max
		std::cout << "\nTotal nodes visited: " << totalVisited;

		std::cout << "\nVisiting all nodes\n";

		for(int i = 0;i < V; i++){
			std::cout << "\nCurrently at node: " << i << "\n\nChecking if its already visited...";
			if(matrix[current * V + i] != 0 && visited[i] == 0){ // if not visited and has edge
				std::cout << "\nIt has not been visited before\n\nComparing cost...";
				if(cost[i] >= matrix[current*V+i]){ // check cost
					cost[i] = matrix[current*V+i];
					previous[i] = current; // set parent
				}
			}
		}

		for(int i = 0; i < V; i++){ // do for all vertices
			if(visited[i] == 0 && cost[i] <= minCost){ // check if visited and if its cost is minimum
				minCost = cost[i]; // if yes update values
				current = i; // set it as next node
			}
		}

		visited[current] = 1; // mark current as visited
		totalVisited++;
	}
	// calculate minimum cost and display mst
	minCost = 0;
	std::cout << "\n\nVertex\t\tPrevious\t\tCost\n\n";
	for(int j = 0; j < V; j++){
		std::cout << "\n" << j << " \t\t " << previous[j] << "\t\t" << cost[j];
		if(cost[j] != INT_MAX){
			minCost += cost[j]; // add cost of current element to min cost
		}
	}
	std::cout << "\n\nMinimum cost is: " << minCost;
}

int find(int i, int parent[]){ // finding parent of a vertex
	while(parent[i] != i)
		i = parent[i]; // back trace parent till i not equal to parent[i] (the initialization value)
	return i;
}

void Graph::sort_edges(){ // using a simple bubble sort to sort edge array on the basis of weight
	Edge temp;
	for(int i = 0; i < E; i++){
		for(int j = 0; j < E - i; j++){
			if(edges[j].weight > edges[j + 1].weight){
				temp = edges[j + 1];
				edges[j + 1] = edges[j];
				edges[j] = temp;
			}
		}
	}
}

void Graph::kruskals(){
	sort_edges(); // step 1 is to sort edges in ascending order
	int min_cost = 0, parent[V]; // Cost of min MST.
	Edge mst[V - 1];
	// Initialize sets of disjoint sets.
	for (int i = 0; i < V; i++)
		parent[i] = i; // every vertex is its own parent
	// Include minimum weight edges one by one
	int count = 0, i = 0;
	while (count != V - 1){
		Edge current_edge = edges[i]; // select an edge

		int source_parent = find(current_edge.source, parent); // get parent of source
		int destination_parent = find(current_edge.destination, parent); // get parent of dest
		// check if they are equal
		if(source_parent != destination_parent){
			mst[count] = current_edge; // if not add to mst
			min_cost += current_edge.weight; // add cost
			count++;
			parent[destination_parent] = source_parent; // set parent
		}
		i++;
	}
	// display edges in mst
	std::cout << "\n\nEDGES IN MST\n\nSr.No.\t\tSource\t\tDestination\t\tWeight\n\n";
	for(int i = 0; i < V - 1; i++){
		std::cout << i << "\t\t" << mst[i].source << "\t\t" << mst[i].destination << "\t\t" << mst[i].weight << "\n";
	}
	std::cout << "\nMinimum cost = " << min_cost;
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

