#include <iostream>
using namespace std;

class Time {
private:
    int hh, mm;

public:
    Time(int h = 0, int m = 0) {
        hh = h;
        mm = m;
    }

    void display() const {
        if (hh < 10) cout << '0';
        cout << hh << ':';

        if (mm < 10) cout << '0';
        cout << mm;
    }

    friend Time laterOf(Time, Time);
};

Time laterOf(Time t1, Time t2) {
    int time1 = t1.hh * 60 + t1.mm;
    int time2 = t2.hh * 60 + t2.mm;

    if (time1 >= time2)
        return t1;
    else
        return t2;
}

int main() {
    Time t1(10, 30);
    Time t2(14, 45);

    cout << "First time: ";
    t1.display();

    cout << "\nSecond time: ";
    t2.display();

    Time later = laterOf(t1, t2);

    cout << "\nLater time: ";
    later.display();

    cout << endl;
    return 0;
}