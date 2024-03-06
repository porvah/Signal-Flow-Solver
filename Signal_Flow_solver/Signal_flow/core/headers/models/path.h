#ifndef PATH_H
#define PATH_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class path {
  private:
      vector<string> nodes;
      vector<double> gains;
      double gain;

public:
    path();
    void addNode(string node);
    void removeNode();
    void removeGain();
    vector<string> getNodes();
    void addGain(double nodeGain);
    void ClaculateGain();
    double getGain();
};
#endif // !PATH_H