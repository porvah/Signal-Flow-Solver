#ifndef LOOPS_H
#define LOOPS_H
#include "../models/path.h"
#include "DFS.h"
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
using namespace std;

class Loops {
private:
	vector<pair<path, double>> loops;
	map<string, pair<path, double>> loopsID;

public:

	void CalculateLoops( map <string, vector<pair<string, double>>>& graph);

	void SetNames();

	map<string, pair<path, double>> getLoops();



};
#endif // !FORWARDPATHS_H