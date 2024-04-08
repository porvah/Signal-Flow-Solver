#ifndef SYSTEMRESULTS_H
#define SYSTEMRESULTS_H
#include <iostream>
#include "../logic/ForwardPaths.h"
#include "../logic/Loops.h"
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
class SystemResults {
private:
    vector<pair<string,double>> Deltas;

    double delta;

    double SystemTransferFunction;

    bool isTouched(vector<string> Path, vector<string> loop);
public:
    void CalculateDeltas(vector<pair<path, double>> paths, map<string, pair<path, double>> loops);

    vector<pair<string,double>> getDeltas();

    void CalculateDelta(map<string, pair<path, double>> individulLoops ,vector<vector<pair<string, double>>> loops);

    double getDelta();

    double CalculateTransferFunction(vector<pair<path, double>> paths);

};
#endif // !SYSTEMRESULTS_H
