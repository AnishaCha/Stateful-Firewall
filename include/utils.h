#pragma once
#include <string>
using namespace std;

string generatekey(string srcip, int srcport, string dstip, int dstport, string proto);
bool ipmatch(string s1, string s2);
