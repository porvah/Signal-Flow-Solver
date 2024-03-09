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

void Graph::CalculateLoops()
{
	loops.CalculateLoops(graph);
}

map<string, pair<path, double>> Graph::getLoops()
{
	return loops.getLoops();
}

map<string, vector<pair<string, double>>> Graph::getGraph()
{
	return graph;
}

void Graph::CalculateNonTouched()
{
	loops.CalculateNonTouching(graph.size());
}

vector<vector<pair<string, double>>> Graph::getNonTouched()
{
	return loops.getNonTouching();
}

void Graph::CalculateDeltas()
{
	result.CalculateDeltas(forwardPaths.getFrorwardPaths(),loops.getLoops());
}

vector<pair<string, double>> Graph::getDeltas()
{
	return result.getDeltas();
}

void Graph::CalculateDelta()
{
	result.CalculateDelta(loops.getLoops(), loops.getNonTouching());
}

double Graph::getDelta()
{
	return result.getDelta();
}

double Graph::getSystemTransferFunction()
{
	return result.CalculateTransferFunction(forwardPaths.getFrorwardPaths());
}
