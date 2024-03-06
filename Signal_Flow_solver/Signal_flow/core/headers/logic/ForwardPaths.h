#ifndef FORWARDPATHS_H
#define FORWARDPATHS_H
#include "../models/path.h"
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
using namespace std;

class ForwardPaths {
 private:
	  vector<pair<path,double>> paths;

public:
	ForwardPaths();


	void CalculateFrorwardPaths(string start, string end, map <string, vector<pair<string, double>>>& graph);

	vector<pair<path,double>> getFrorwardPaths();

	void DFS(string start, string end, path& p, unordered_set<string>& visited, map <string, vector<pair<string, double>>>& graph);


};



#endif // !FORWARDPATHS_H