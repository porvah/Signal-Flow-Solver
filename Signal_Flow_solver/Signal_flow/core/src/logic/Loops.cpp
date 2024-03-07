#include "../../headers/logic/Loops.h"

void Loops::CalculateLoops( map<string, vector<pair<string, double>>>& graph)
{
	DFS d;
	path p;
	unordered_set <string> visited;
	for (auto const& x : graph) {
		d.dfs(x.first, x.first, p, visited, loops, graph,false);
	}

}

void Loops::SetNames()
{
	for (int i = 0; i < loops.size(); i++) {
		loopsID["L"+to_string(i)] = loops[i];
	}
}

map<string, pair<path, double>> Loops::getLoops()
{
	SetNames();
	return loopsID;
}




