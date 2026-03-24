#include "utils.h"
#include <sstream>

using u32 = unsigned int;

string generatekey(string srcip, int srcport, string dstip, int dstport, string proto) {
    return srcip + ":" + to_string(srcport) + ":" + dstip + ":" + to_string(dstport) + proto;
}

bool ipmatch(string s1, string s2) {
    if (s1 == "ANY") return true;

    auto pos = s1.find('/');
    string ip = s1.substr(0, pos);
    int prefix1 = stoi(s1.substr(pos + 1));

    unsigned int a, b, c, d;
    char ch;

    stringstream ss(ip);
    ss >> a >> ch >> b >> ch >> c >> ch >> d;

    u32 ip1 = ((u32)a << 24) | ((u32)b << 16) | ((u32)c << 8) | (u32)d;

    u32 mask1 = (prefix1 == 0) ? 0u : (0xFFFFFFFFu << (32 - prefix1));
    u32 base = mask1 & ip1;

    stringstream ss1(s2);
    ss1 >> a >> ch >> b >> ch >> c >> ch >> d;

    u32 packetip = ((u32)a << 24) | ((u32)b << 16) | ((u32)c << 8) | (u32)d;

    return ((packetip & mask1) == base);
}
