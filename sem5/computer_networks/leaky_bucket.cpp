#include <iostream>
#include <vector>
using namespace std;

#define BUCKET_SIZE 300
#define LEAK_RATE 60

int main() {
    // packet size -> time
    vector<pair<int, int>> packets = {
        {50, 0}, {100, 1}, {175, 2}, {50, 3}, {150, 4}, {200, 5},
    };

    // simulate leaky bucket
    int filled = 0;
    for (auto& [packet_size, time] : packets) {
        cout << "At time " << time << " received packet of size " << packet_size
             << endl;
        if (filled + packet_size > BUCKET_SIZE) {
            cout << "Bucket overflow!, packet dropped" << endl;
        } else {
            cout << "Packet stored in bucket" << endl;
            filled += packet_size;
        }
        int leaked = min(filled, LEAK_RATE);
        cout << "\nBucket size: " << filled << endl;
        cout << "Leaked " << leaked << " amount of data in uniform manner"
             << endl;
        filled -= leaked;
        cout << "Bucket size now: " << filled << endl << endl;
    }
    while (filled != 0) {
        int leaked = min(filled, LEAK_RATE);
        cout << "\nBucket size: " << filled << endl;
        cout << "Leaked " << leaked << " amount of data in uniform manner"
             << endl;
        filled -= leaked;
        cout << "Bucket size now: " << filled << endl << endl;
    }
    return 0;
}
