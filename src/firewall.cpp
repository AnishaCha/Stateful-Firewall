#include "firewall.h"
#include "utils.h"
#include <iostream>

using namespace std;

Firewall::Firewall() {
    policy = {
        {"192.168.1.0/24", "ANY", 80, "ALLOW", "TCP"},
        {"192.168.1.0/24", "ANY", 443, "ALLOW", "TCP"},
        {"192.168.1.0/24", "ANY", 0, "DENY", "TCP"},
        {"ANY", "192.168.1.100", 22, "ALLOW", "TCP"}
    };
}

void Firewall::processPacket(string srcip, int srcport, string dstip, int dstport, string proto) {

    string key = generatekey(srcip, srcport, dstip, dstport, proto);
    string revkey = generatekey(dstip, dstport, srcip, srcport, proto);

    if (stateTable.count(key)) {
        cout << "State HIT: " << stateTable[key].ruleaction << endl;
        stateTable[key].last = chrono::system_clock::now();
        return;
    }

    if (stateTable.count(revkey)) {
        cout << "Reverse HIT: " << stateTable[revkey].ruleaction << endl;
        stateTable[revkey].last = chrono::system_clock::now();
        return;
    }

    string action = "DENY";

    for (auto &rule : policy) {
        bool srcmatch = ipmatch(rule.srcip, srcip);
        bool dstmatch = ipmatch(rule.dstip, dstip);
        bool portmatch = (rule.dstPort == 0) || (rule.dstPort == dstport);
        bool protomatch = (rule.protocol == "ANY") || (rule.protocol == proto);

        if (srcmatch && dstmatch && portmatch && protomatch) {
            action = rule.action;
            break;
        }
    }

    if (action == "ALLOW") {
        flowstate flow;
        flow.revkey = revkey;
        flow.last = chrono::system_clock::now();
        flow.ruleaction = action;

        stateTable[key] = flow;

        cout << "New state entry created" << endl;
    } else {
        cout << "Packet DENIED" << endl;
    }
}
