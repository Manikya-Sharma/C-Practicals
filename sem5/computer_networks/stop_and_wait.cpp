#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> send_queue = {1, 2, 3, 4, 5, 6};
    vector<int> receive_queue;

    int lost_ack = 6;
    int lost_packet = 4;

    for (int i = 0; i < send_queue.size(); i++) {
        cout << "\n\n";
        cout << "*** SENDER ***" << endl;
        cout << "Sending packet " << send_queue[i] << " ..." << endl;

        if (send_queue[i] == lost_packet) {
            cout << "*** RECEIVER ***" << endl;
            cout << "Timeout: Packet not received" << endl;
            cout << "*** SENDER ***" << endl;
            cout << "Timeout: Acknowledgement not received: sending packed "
                 << send_queue[i] << " again" << endl;
            lost_packet = -1;
            i--;
            continue;
        } else {
            cout << "*** RECEIVER ***" << endl;
            cout << "Packet received: sending ack for " << send_queue[i]
                 << endl;
            cout << "*** SENDER ***" << endl;
            if (send_queue[i] == lost_ack) {
                cout << "Acknowledgement not recieved: sending packet "
                     << send_queue[i] << " again" << endl;
                lost_ack = -1;
                i--;
                continue;
            } else {
                cout << "Acknowledgement recieved: sending next packet" << endl;
            }
        }
        receive_queue.push_back(send_queue[i]);
    }

    cout << "Final data received:-" << endl;
    for (auto& elem : receive_queue) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
