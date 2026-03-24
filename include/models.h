#pragma once
#include <string>
#include <chrono>
using namespace std;

struct flowstate {
    string revkey;
    chrono::system_clock::time_point last;
    string ruleaction;
};

struct Rule {
    string srcip;
    string dstip;
    int dstPort;
    string action;
    string protocol;
};
