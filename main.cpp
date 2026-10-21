
#include <iostream>
using namespace std;

int main() {
    int cycle[3] = {30, 40, 50};
    int offset[3] = {5, 10, 20};
    int duration[3] = {10, 10, 10};
    int travel[3] = {0, 8, 18};

    int startTime;
    bool found = false;

    for (startTime = 0; startTime <= 1000; startTime++) {
        bool green = true;

        for (int i = 0; i < 3; i++) {
            int arrival = startTime + travel[i];
            int phase = arrival % cycle[i];
            int difference = (phase - offset[i] + cycle[i])
                             % cycle[i];

            if (difference >= duration[i]) {
                green = false;
                break;
            }
        }

        if (green) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "\n========== RESULTS ==========\n";
        cout << "Calculated ambulance starting time: "
             << startTime << " seconds\n";

        for (int i = 0; i < 3; i++) {
            int arrival = startTime + travel[i];
            int phase = arrival % cycle[i];

            cout << "\nSignal " << i + 1 << ":\n";
            cout << "Ambulance arrival time: "
                 << arrival << " seconds\n";
            cout << "Signal cycle position: "
                 << phase << " seconds\n";
            cout << "Status: GREEN - corridor condition met\n";
        }

        cout << "\nFinal result: GREEN CORRIDOR CONDITIONS SATISFIED\n";
    } else {
        cout << "No common starting time found.\n";
    }

    cout << "\nNote: This is a mathematical simulation. "
         << "It does not control physical traffic lights.\n";

    return 0;
}
