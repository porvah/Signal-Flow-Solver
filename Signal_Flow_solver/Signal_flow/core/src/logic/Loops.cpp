#include "../../headers/logic/Loops.h"
/*calculate all individual loops*/
void Loops::CalculateLoops( map<string, vector<pair<string, double>>>& graph)
{
	DFS d;
	path p;
	unordered_set <string> visited;
	for (auto const& x : graph) {
		d.dfs(x.first, x.first, p, visited, loops, graph,false);
	}

}
/*set a name for each loop*/
void Loops::SetNames()
{
	for (int i = 0; i < loops.size(); i++) {
		loopsID["L"+to_string(i)] = loops[i];
	}
}
/*return all individual loops*/
map<string, pair<path, double>> Loops::getLoops()
{
	SetNames();
	return loopsID;
}
/*calculate all non Touched loops*/
void Loops::CalculateNonTouching(int nodesNum)
{
	NonTouched nonTouched;
	nonTouched.FindNontouched(loopsID, nontouched,nodesNum);
}
/*return all non touched loops*/
vector<vector<pair<string, double>>> Loops::getNonTouching()
{
	return nontouched;
}




