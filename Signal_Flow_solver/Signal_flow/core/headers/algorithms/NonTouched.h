#ifndef NONTOUCHED_H
#define NONTOUCHED_H
#include <iostream>
#include "../logic/ForwardPaths.h"
#include "../logic/Loops.h"
#include "vector"
#include "map"
#include "string"
using namespace std;
class NonTouched {

public:
    void FindNontouched(map<string, pair<path, double>>& loopsID, vector<vector<pair<string, double>>>& nontouched, int nodesNum);

    bool isTouched(vector<string> firstLoop, vector<string> secondLoop);

    bool IsExisted(string loopName, vector<tuple<string, path, double>> combinations);
};
#endif // !NONTOUCHED_H