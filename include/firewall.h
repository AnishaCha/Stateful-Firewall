#pragma once
#include <map>
#include <vector>
#include "models.h"
using namespace std;

class Firewall {
private:
    map<string, flowstate> stateTable;
    vector<Rule> policy;

public:
    Firewall();
    void processPacket(string srcip, int srcport, string dstip, int dstport, string proto);
};
