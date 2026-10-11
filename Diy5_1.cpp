#include <iostream>
using namespace std;

class Counter {
private:
    static int totalCreated;
    static int currentlyAlive;

public:
    Counter() {
        totalCreated++;
        currentlyAlive++;
    }

    Counter(const Counter&) {
        totalCreated++;
        currentlyAlive++;
    }

    ~Counter() {
        currentlyAlive--;
    }

    static void showCounts() {
        cout << "Total objects created: "
             << totalCreated << endl;
        cout << "Currently alive: "
             << currentlyAlive << endl;
    }
};

// Initialize static members
int Counter::totalCreated = 0;
int Counter::currentlyAlive = 0;

int main() {
    Counter::showCounts();

    Counter c1, c2;
    Counter::showCounts();

    {
        Counter c3;
        Counter::showCounts();
    }

    Counter::showCounts();

    return 0;
}