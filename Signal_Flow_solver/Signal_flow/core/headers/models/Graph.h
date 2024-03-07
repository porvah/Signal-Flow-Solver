#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <map>
#include "../logic/ForwardPaths.h"
#include <string>
using namespace std;

class Graph {
   private: 
	   map <string,vector<pair<string, double>>> graph;
	   ForwardPaths forwardPaths;
   
   public:

	   void addNode(string node);

	   void connect(string from, string to,double gain);

	   void CalculatePaths();

	   vector<pair<path,double>> getPaths();

	   map <string, vector<pair<string, double>>> getGraph();
	   


};
#endif // !GRAPH_H
