#include "../../headers/models/path.h"

path::path()
{
	gain = 1; // set the gain of the first node to one
	gains.push_back(1);
}

void path::addNode(string node)
{
	nodes.push_back(node);
}

void path::removeNode()
{
	nodes.pop_back();
}


void path::removeGain()
{
	gains.pop_back();
}

vector<string> path::getNodes()
{
	return nodes;
}

vector<double> path::getgains()
{
	return gains;
}

void path::addGain(double nodeGain)
{
	gains.push_back(nodeGain);
}
/*calculate the total gain of the path*/
void path::ClaculateGain()
{
	gain = 1;
	for (int i = 0; i < gains.size(); i++)
		gain *= gains[i];
}

double path::getGain() 
{
	return gain;
}
