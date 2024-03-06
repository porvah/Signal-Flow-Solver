#include "../../headers/logic/ForwardPaths.h"
using namespace std;

ForwardPaths::ForwardPaths()
{
	paths = vector<pair<path,double>>();
}


void ForwardPaths::CalculateFrorwardPaths(string start, string end, map<string, vector<pair<string, double>>>& graph) 
{
	path p;
	unordered_set <string> visited;
	DFS(start, end, p, visited, graph);

}

vector<pair<path,double>> ForwardPaths::getFrorwardPaths()
{

	return paths;
}

void ForwardPaths::DFS(string start, string end, path& p, unordered_set<string>& visited, map<string, vector<pair<string, double>>>& graph)
{
	visited.insert(start);
	p.addNode(start);
	if (start == end) {
		p.ClaculateGain();
		paths.push_back(make_pair(p,p.getGain()));
	}
	else {
		for (int i = 0; i < graph[start].size(); i++) {
			if (visited.find(graph[start][i].first) == visited.end()) {
				p.addGain(graph[start][i].second);
				DFS(graph[start][i].first, end, p, visited, graph);
			}
		}
	}
	if (!p.getNodes().empty()) {
		p.removeNode();
		p.removeGain();
	}
	visited.erase(start);
}
