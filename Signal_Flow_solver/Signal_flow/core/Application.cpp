#include<iostream>
#include "./headers/models/Graph.h"

int main() {
	Graph g;
	g.addNode("start");
	g.addNode("y2");
	g.addNode("y3");
	g.addNode("y4");
	g.addNode("y5");
	g.addNode("y6");
	g.addNode("end");
	g.connect("start", "y2", 1);
	g.connect("y2", "y3", 5);
	g.connect("y2", "y6",10);
	g.connect("y3", "y4", 10);
	g.connect("y4", "y3", -1);
	g.connect("y4", "y5", 2);
	g.connect("y5", "y4", -2);
	g.connect("y5", "end", 1);
	g.connect("y6", "y5", 2);
	g.connect("y6", "y6", -1);
	map<string, vector<pair<string, double>>> mp = g.getGraph();
	g.CalculatePaths();
	vector<pair<path, double>> v = g.getPaths();
	for (auto const& x : mp)
	{
		cout << x.first << ':';
		for (int i = 0; i < mp[x.first].size(); i++) {
			cout << "(" << mp[x.first][i].first << ", " << mp[x.first][i].second << "),";

		}
		cout << "\n";
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].first.getNodes().size(); j++) {
			cout << v[i].first.getNodes()[j] << ",";
		}
		cout << v[i].second << endl;
	}

	
	return 0;
}