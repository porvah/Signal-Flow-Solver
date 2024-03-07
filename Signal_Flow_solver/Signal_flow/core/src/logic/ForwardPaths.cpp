#include "../../headers/logic/ForwardPaths.h"



void ForwardPaths::CalculateFrorwardPaths(const string& start,const string& end, map<string, vector<pair<string, double>>>& graph) 
{
	path p;
	unordered_set <string> visited;
	DFS d;
	d.dfs(start, end, p, visited, paths, graph,true);

}

vector<pair<path,double>> ForwardPaths::getFrorwardPaths()
{

	return paths;
}

