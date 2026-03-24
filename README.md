# Stateful Firewall (C++)

A simple **stateful packet filtering firewall** implemented in C++.
This project demonstrates core networking and system design concepts like flow tracking, rule-based filtering, and CIDR matching.

---

## Features

* Stateful packet inspection
* Rule-based filtering (ALLOW / DENY)
* CIDR-based IP matching
* Forward and reverse flow handling
* 5-tuple flow identification
* Modular, multi-file C++ project structure

---

## Key Concepts

* **5-tuple flow key**

  ```
  (srcIP, srcPort, dstIP, dstPort, protocol)
  ```

* **State Table**

  * Tracks active flows
  * Enables reverse traffic automatically

* **CIDR Matching**

  * Efficient IP range filtering using bit masking

---

## Project Structure

```
stateful-firewall/
│── src/
│   ├── main.cpp
│   ├── firewall.cpp
│   ├── utils.cpp
│
│── include/
│   ├── firewall.h
│   ├── models.h
│   ├── utils.h
│
│── CMakeLists.txt
│── README.md
```

---

## Build & Run

### Using g++

```bash
g++ src/*.cpp -Iinclude -o firewall
./firewall
```

---

### Using CMake

```bash
mkdir build
cd build
cmake ..
make
./firewall
```

---

## Example Rules

```cpp
{"192.168.1.0/24", "ANY", 80, "ALLOW", "TCP"},   // HTTP
{"192.168.1.0/24", "ANY", 443, "ALLOW", "TCP"},  // HTTPS
{"192.168.1.0/24", "ANY", 0, "DENY", "TCP"},     // Deny others
{"ANY", "192.168.1.100", 22, "ALLOW", "TCP"}     // SSH inbound
```

---

## Example Flow

1. Outgoing request allowed → stored in state table
2. Incoming response → automatically allowed (reverse lookup)
3. Unmatched traffic → denied

---

## Sample Output

```
New state entry created
Reverse HIT: ALLOW
Packet DENIED
New state entry created
```

---

## 💡 Use Cases

* Network security systems
* Firewall simulation
* System design interviews
* Learning low-level networking

---

## 🧑‍💻 Author

**Anisha Chauhan**

---

## ⭐ If you like this project

Give it a star ⭐ and feel free to contribute!

