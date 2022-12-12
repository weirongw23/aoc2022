#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int top = 3;

int main() {
    priority_queue<int, vector<int>, std::greater<>> pq;
    string calories;
    int currentCalories = 0;

    while (getline(cin, calories)) {
        if (!isdigit(calories[0])) {
            pq.push(currentCalories);

            if (pq.size() > top) {
                pq.pop();
            }

            currentCalories = 0;
            continue;
        }

        try {
            currentCalories += stoi(calories);
        } catch(...) {
            break;
        }
    }

    pq.push(currentCalories);
    if (pq.size() > top) {
        pq.pop();
    }

    int total = 0;
    for (int i = 0; i < top; ++i) {
        cout << "Top " << top - i << ": " << pq.top() << endl;
        total += pq.top();
        pq.pop();
    }

    cout << "Sum of calories carried by these three elves is " << total << endl;
}
