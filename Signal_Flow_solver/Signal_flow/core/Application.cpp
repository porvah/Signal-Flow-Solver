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
    /*g.addNode("start");
	g.addNode("y1");
	g.addNode("y2");
	g.addNode("y3");
	g.addNode("y4");
	g.addNode("y5");
	g.addNode("y6");
	g.addNode("y7");
	g.addNode("end");
	g.connect("start", "y1", 1);
	g.connect("y1", "y2", 2);
	g.connect("y2", "y3", 3);
	g.connect("y3", "y4", 4);
	g.connect("y4", "y5", 5);
	g.connect("y5", "end", 1);
	g.connect("y5", "y6", 3);
	g.connect("y6", "y7", 2);
	g.connect("y7", "y6", 1);
	g.connect("y7", "y1", 2);
	g.connect("y2", "y1", 3);
	g.connect("y4", "y3", 3);*/
	/*g.addNode("start");
	g.addNode("y1");
	g.addNode("y2");
	g.addNode("y3");
	g.addNode("y4");
	g.addNode("y5");
	g.addNode("end");
	g.connect("start", "y1", 1);
	g.connect("y1", "y2", 2);
	g.connect("y2", "y3", 3);
	g.connect("y3", "y4", 4);
	g.connect("y4", "y5", 5);
	g.connect("y5", "end", 1);
	g.connect("y1", "y1", 2);
	g.connect("y2", "y2", 2);
	g.connect("y3", "y3", 2);
	g.connect("y4", "y4", 2);
	g.connect("y5", "y5", 2);*/
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
	cout << "NontouchedLoops:" << endl;
	g.CalculateNonTouched();
	vector<vector<pair<string, double>>> NonTouched = g.getNonTouched();
	for (int i=0;i<NonTouched.size();i++)
	{
		for (int j = 0; j < NonTouched[i].size(); j++) {
			cout << NonTouched[i][j].first << ':';
			cout << "gain =" << NonTouched[i][j].second;
			cout << "\n";
		}
	}
	cout << "Deltas:" << endl;
	g.CalculateDeltas();
	vector<pair<string, double>> deltas = g.getDeltas();
	for (int i = 0; i < deltas.size(); i++) {
		cout << deltas[i].first << "=";
		cout << deltas[i].second << endl;
	}
	cout << "Delta=";
	g.CalculateDelta();
	cout << g.getDelta() << endl;
	cout << "Transfer Function ="<< g.getSystemTransferFunction();
	return 0;

	// test comment delete me if you find me
}