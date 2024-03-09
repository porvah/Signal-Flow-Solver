#ifndef DFS_H
#define DFS_H
#include <iostream>
#include "../logic/ForwardPaths.h"
#include "../logic/Loops.h"
#include "unordered_set"
#include "map"
class DFS {

   public:
       void dfs(const string& start, const string& end, path& p, unordered_set<string>& visited, vector<pair<path, double>>& paths, map <string, vector<pair<string, double>>>& graph,bool indicator);

       bool Found(vector<string> nodes,vector <pair<path, double>> loops);
};
#endif // !DFS_H