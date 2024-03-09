#ifndef FORWARDPATHS_H
#define FORWARDPATHS_H
#include "../models/path.h"
#include "../algorithms/DFS.h"
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

	void CalculateFrorwardPaths(const string& start, const string& end, map <string, vector<pair<string, double>>>& graph);

	vector<pair<path,double>> getFrorwardPaths();


};



#endif // !FORWARDPATHS_H