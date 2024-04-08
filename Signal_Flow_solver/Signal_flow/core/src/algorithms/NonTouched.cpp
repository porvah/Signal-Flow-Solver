#include "../../headers/algorithms/NonTouched.h"
#include <algorithm>

/*logic to calculate all non touched loops*/
void NonTouched::FindNontouched(map<string, pair<path, double>>& loopsID, vector<vector<pair<string, double>>>& nontouched,int nodesNum)
{
        vector<tuple<string, path, double>> v;
        vector<vector<tuple<string, path, double>>> combinations; // stores all combinations of non touched loops
        for (auto const& x : loopsID)
            v.push_back(make_tuple(x.first, loopsID[x.first].first, loopsID[x.first].second));

        combinations.push_back(v);
        vector<pair<string, double>> temp; // to stroe the nodes 
        vector<tuple<string, path, double>> temp1; // to store the path without nodes
        int index = 0;
        for (int k = 2; k <= nodesNum; k++) {
            for (int i = 0; i < v.size(); i++) {
                for (int j = i+1 ; j < combinations[k-2].size(); j++) {
                    if (!isTouched(get<1>(v[i]).getNodes(), get<1>(combinations[k - 2][j]).getNodes())) {
                        path p;
                        for (int x = 0; x < get<1>(v[i]).getNodes().size(); x++)
                            p.addNode(get<1>(v[i]).getNodes()[x]);
                        for (int y = 0; y < get<1>(combinations[k -2][j]).getNodes().size(); y++)
                            p.addNode(get<1>(combinations[k - 2][j]).getNodes()[y]);
                        if (!IsExisted((get<0>(v[i]) + get<0>(combinations[k - 2][j])),temp1)) {
                             temp.push_back(make_pair(get<0>(v[i]) + get<0>(combinations[k - 2][j]), get<2>(v[i]) * get<2>(combinations[k - 2][j])));
                            temp1.push_back(make_tuple(get<0>(v[i]) + get<0>(combinations[k - 2][j]), p, get<2>(v[i]) * get<2>(combinations[k - 2][j])));
                        }
                    }

                }
            }
            
            nontouched.push_back(temp);
            combinations.push_back(temp1);
            temp.clear();
            temp1.clear();
        }
        
    
}
/*check if the loops are touched*/
bool NonTouched::isTouched(vector<string> firstLoop, vector<string> secondLoop)
{
    for (int i = 0; i < firstLoop.size(); i++) {
        if (find(secondLoop.begin(), secondLoop.end(), firstLoop[i]) != secondLoop.end())
            return true;
    }
    return false;
}
/* check for the existance of the loops to avoid duplication*/
bool NonTouched::IsExisted(string loopName, vector<tuple<string, path, double>> combinations)
{  
    int count = 0;
    for (int j = 0; j < combinations.size(); j++) {
        for (int i = 0; i < loopName.length(); i+=2) {
            string s = loopName.substr(i, 2); // get the name of the loop
            if (get<0>(combinations[j]).find(s) != string::npos) {
                count++;
            }
            else
                break;

        }
        if (count == loopName.length() / 2)
            return true;
        count = 0;
    }
    return false;
}
