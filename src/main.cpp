#include "firewall.h"

int main() {
    Firewall fw;

    fw.processPacket("192.168.1.10", 50000, "203.0.113.1", 80, "TCP");
    fw.processPacket("203.0.113.1", 80, "192.168.1.10", 50000, "TCP");
    fw.processPacket("192.168.1.10", 50001, "8.8.8.8", 53, "UDP");
    fw.processPacket("10.0.0.5", 40000, "192.168.1.100", 22, "TCP");

    return 0;
}
