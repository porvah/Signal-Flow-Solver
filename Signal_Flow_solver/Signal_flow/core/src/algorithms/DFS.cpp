#include "../../headers/algorithms/DFS.h"
#include <algorithm>
/*graph traversal*/
void DFS::dfs(const string& start, const string& end, path& p, unordered_set<string>& visited, vector<pair<path, double>>& paths, map<string, vector<pair<string, double>>>& graph,bool indicator)
{
    visited.insert(start); // mark the node as visited
    p.addNode(start);

    if(indicator){ // forward paths calculation
        if (start == end && visited.size() > 0 ) {
            p.ClaculateGain();
            paths.push_back(make_pair(p, p.getGain()));
        }
        else {
            for (int i = 0; i < graph[start].size(); i++) {
                if (visited.find(graph[start][i].first) == visited.end()) {
                    p.addGain(graph[start][i].second);
                    dfs(graph[start][i].first, end, p, visited, paths, graph, indicator);

                }
            }
        }
    }
    else if (!indicator) {// loops calculation
        for (int i = 0; i < graph[start].size(); i++) {
            if (graph[start][i].first == end && visited.size() > 0) {
                p.addGain(graph[start][i].second);
                p.addNode(graph[start][i].first);
                p.ClaculateGain();
                if(!Found(p.getNodes(),paths))
                    paths.push_back(make_pair(p, p.getGain()));
                p.removeGain();
                p.removeNode();
            }
            else if (visited.find(graph[start][i].first) == visited.end()) {
                p.addGain(graph[start][i].second);
                dfs(graph[start][i].first, end, p, visited, paths, graph, indicator);

            }
        }
    }
    if (!p.getNodes().empty())
        p.removeNode();

    if (!p.getgains().empty())
        p.removeGain();

    visited.erase(start);

}
/*check for the existance of the loop to avoid duplication*/
bool DFS::Found(vector<string> nodes, vector<pair<path, double>> loops)
{
    int count = 0;
    for (int i = 0; i < loops.size(); i++) {
        for (int j = 0; j < loops[i].first.getNodes().size(); j++) {
            if (find(nodes.begin(), nodes.end(), loops[i].first.getNodes()[j]) == nodes.end()) {
                count = 0;
                break;
            }
            count++;
        }
        if (count == nodes.size())
            return true;
        count = 0;
    }
    return false;
}
