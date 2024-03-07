#include "../../headers/models/Graph.h"


void Graph::addNode(string node)
{
	graph[node] = vector<pair<string, double>>();
}

void Graph::connect(string from, string to, double gain)
{
	graph[from].push_back(make_pair(to, gain));
}

void Graph::CalculatePaths()
{
	forwardPaths.CalculateFrorwardPaths("start","end",graph);
}

vector<pair<path, double>> Graph::getPaths()
{
	return forwardPaths.getFrorwardPaths();
	
}

map<string, vector<pair<string, double>>> Graph::getGraph()
{
	return graph;
}
