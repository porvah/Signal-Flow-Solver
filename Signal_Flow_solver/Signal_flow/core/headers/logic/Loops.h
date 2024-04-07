#ifndef LOOPS_H
#define LOOPS_H
#include "../models/path.h"
#include "../algorithms/DFS.h"
#include "../algorithms/NonTouched.h"
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
	vector<vector<pair<string, double>>> nontouched;

	void SetNames();

public:

	void CalculateLoops( map <string, vector<pair<string, double>>>& graph);

	map<string, pair<path, double>> getLoops();

	void CalculateNonTouching(int nodesNum) ;

	vector<vector<pair<string, double>>> getNonTouching();



};
#endif // !LOOPS_H