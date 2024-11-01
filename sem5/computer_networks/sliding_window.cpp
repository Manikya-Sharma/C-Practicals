#include <iostream>
#include <vector>
using namespace std;

const int WINDOW_SIZE = 4;

void sliding_window(vector<int>& sender_queue, int lost_packet, int lost_ack) {
    int n = (int)sender_queue.size();
    // Sender
    cout << "\n==================\n" << endl;
    cout << "** SENDER **" << endl;

    vector<pair<int, int>> buffer;

    int j = 0;
    while (j < min(WINDOW_SIZE, n)) {
        cout << "Sending packet: " << j << endl;
        if (lost_packet == j) {
            cout << "Packet number " << j << " lost during transmission"
                 << endl;
        } else {
            buffer.push_back({j, sender_queue[j]});
        }
        j++;
    }

    // Receiver
    int last_received = -1;
    bool flag = false;
    for (int t = 0; t < buffer.size(); t++) {
        cout << "** RECEIVER ** " << endl;
        if (lost_packet == t) {
            flag = true;
            cout << "!! Packet number " << t << " not received!" << endl;
            cout << "** SENDER ** " << endl;
            cout << "!! Ack for packet number " << t << " not received!"
                 << endl;
            continue;
        }
        if (flag) {
            cout << "!! Packet number " << t << " ignored!" << endl;
            cout << "** SENDER ** " << endl;
            cout << "!! Ack for packet number " << t << " not received!"
                 << endl;
            last_received++;
        } else {
            cout << "Received packet number " << t << " with data "
                 << buffer[t].first << endl;
            cout << "Send acknowlegdement" << endl;
            if (lost_ack == t) {
                cout << "Acknowledegment lost during transmission" << endl;
                cout << "** SENDER ** " << endl;
                cout << "!! Ack for packet number not " << t << " received!"
                     << endl;
                last_received++;
            }
            cout << "** SENDER ** " << endl;
            cout << "Ack for packet number " << t << " received!" << endl;
            if (j + 1 < n) {
                cout << "Sending packet number " << (j + 1) << endl;
                buffer.push_back({t, sender_queue[j]});
                j++;
            }
            last_received = (last_received + 1) % WINDOW_SIZE;
        }
    }
    // In go-back-n, sender needs to resend complete data
    if (lost_ack != -1 || lost_packet != -1) {
        cout << "Sender will send the packets again" << endl;
        if (flag)
            sliding_window(sender_queue, -1, lost_ack);
        else
            sliding_window(sender_queue, lost_packet, -1);
    }
}

int main() {
    vector<int> sender_queue = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    sliding_window(sender_queue, 2, 4);

    return 0;
}
