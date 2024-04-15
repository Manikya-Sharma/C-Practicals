#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void scan(int* requests, int head, int direction, int size, int disk_size) {
    int seek_count = 0;
    int distance, position;
    vector<int> smaller, larger;
    vector<int> sequence;

    // add sentinel values
    if (direction == 0) {
        smaller.push_back(0);
    } else if (direction == 1) {
        larger.push_back(disk_size - 1);
    }

    for (int i = 0; i < size; i++) {
        if (requests[i] < head)
            smaller.push_back(requests[i]);
        if (requests[i] > head)
            larger.push_back(requests[i]);
    }

    sort(smaller.begin(), smaller.end());
    sort(larger.begin(), larger.end());

    // loop only to sun in 2 directions
    for (int i=0; i<2; i++) {
        if (direction == 0) {
            for (int i = smaller.size() - 1; i >= 0; i--) {
                position = smaller[i];
                sequence.push_back(position);
                distance = abs(position - head);
                seek_count += distance;
                head = position;
            }
            direction = 1;
        } else if (direction == 1) {
            for (int i = 0; i < larger.size(); i++) {
                position = larger[i];
                sequence.push_back(position);
                distance = abs(position - head);
                seek_count += distance;
                head = position;
            }
            direction = 0;
        }
    }
    cout << "Seek Sequence: ";
    for (int i = 0; i < sequence.size(); i++) {
        cout << sequence[i] << " ";
    }
    cout << endl;
    cout << "Total seek count: " << seek_count << endl;
}

int main() {
    int size = 8;
    int disk_size = 200;
    int requests[8] = {176, 79, 34, 60, 92, 11, 41, 114};
    int initial_position = 50;
    // initialize with left direction
    int direction = 0;
    scan(requests, initial_position, direction, size, disk_size);
    return 0;
}
