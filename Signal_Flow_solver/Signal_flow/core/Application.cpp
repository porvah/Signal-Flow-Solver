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
	g.connect("y5", "y2", -1);
	g.connect("y5", "end", 1);
	g.connect("y6", "y5", 2);
	g.connect("y6", "y6", -1);
	map<string, vector<pair<string, double>>> mp = g.getGraph();
	g.CalculatePaths();
	vector<pair<path, double>> v = g.getPaths();
	cout << "Graph:" << endl;
	for (auto const& x : mp)
	{
		cout << x.first << ':';
		for (int i = 0; i < mp[x.first].size(); i++) {
			cout << "(" << mp[x.first][i].first << ", " << mp[x.first][i].second << "),";

		}
		cout << "\n";
	}
	cout << "Forward Paths:" << endl;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].first.getNodes().size(); j++) {
			cout << v[i].first.getNodes()[j] << ",";
		}
		cout << v[i].second << endl;
	}
	cout << "Loops:" << endl;
	g.CalculateLoops();
	map<string, pair<path, double>> loops = g.getLoops();
	for (auto const& x : loops)
	{
		cout << x.first << ':';
		for (int i = 0; i < loops [x.first].first.getNodes().size() ; i++) {
			cout << loops[x.first].first.getNodes()[i] << ",";

		}
		cout << "gain =" << loops[x.first].second;
		cout << "\n";
	}
	
	return 0;

	// test comment delete me if you find me
}