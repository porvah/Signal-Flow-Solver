#include "../../headers/algorithms/SystemResults.h"
/* calculate the values of all deltas*/
void SystemResults::CalculateDeltas(vector<pair<path, double>> paths, map<string, pair<path, double>> loops)
{
	double d = 1;
	for (int i = 0; i < paths.size(); i++) {
		for (auto const& x : loops) {
			if (!isTouched(paths[i].first.getNodes(), loops[x.first].first.getNodes()))
				d -= loops[x.first].second;
		}
		Deltas.push_back(make_pair("d"+to_string(i),d));
		d = 1;
	}

}
/*return the values of deltas*/
vector<pair<string, double>> SystemResults::getDeltas()
{
	return Deltas;
}
/* calculate delta*/
void SystemResults::CalculateDelta(map<string, pair<path, double>> individulLoops,vector<vector<pair<string, double>>> loops)
{
	delta = 1;
	for (auto const& x : individulLoops) {
		delta -= individulLoops[x.first].second;
	}
	for (int i = 0; i < loops.size(); i++) {
		for (int j = 0; j < loops[i].size(); j++) {
			if (i % 2 == 0)
				delta += loops[i][j].second;
			else
				delta -= loops[i][j].second;
		}
	}

}
/* return the value of delta */
double SystemResults::getDelta()
{
	return delta;
}
/* calculate the system transfer function value */
double SystemResults::CalculateTransferFunction(vector<pair<path, double>> paths)
{
	double c=0;
	for (int i = 0; i < paths.size(); i++) {
		c += paths[i].second * Deltas[i].second;
	}
	SystemTransferFunction = c / delta;
	return SystemTransferFunction;
}
/*check whether the path and a loop are touched*/
bool SystemResults::isTouched(vector<string> Path, vector<string> loop)
{
	for (int i = 0; i < Path.size(); i++) {
		if (find(loop.begin(), loop.end(), Path[i]) != loop.end())
			return true;
	}
	return false;
}
