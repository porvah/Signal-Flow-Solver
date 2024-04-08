#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <map>
#include "../logic/ForwardPaths.h"
#include "../logic/Loops.h"
#include "../algorithms/SystemResults.h"
#include <string>
using namespace std;

class Graph {
   private: 
	   map <string,vector<pair<string, double>>> graph;
	   ForwardPaths forwardPaths;
	   Loops loops;
	   SystemResults result;
   
   public:
       Graph(map <string,vector<pair<string, double>>> map);
	   void addNode(string node);

	   void connect(string from, string to,double gain);

	   void CalculatePaths();

	   vector<pair<path,double>> getPaths();

	   void CalculateLoops();

	   map<string, pair<path, double>> getLoops();

	   map <string, vector<pair<string, double>>> getGraph();

	   void CalculateNonTouched();

	   vector<vector<pair<string, double>>> getNonTouched();

	   void CalculateDeltas();

	   vector<pair<string, double>> getDeltas();

	   void CalculateDelta();

	   double getDelta();

	   double getSystemTransferFunction();
	   


};
#endif // !GRAPH_H
