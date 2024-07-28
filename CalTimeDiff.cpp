#include <bits/stdc++.h>

using namespace std;

class Time {
    int hour, minute;

public:
    Time() : hour(0), minute(0) {}

    void setTime(int h, int m) {
        hour = h;
        minute = m;
    }

    double diffInHours(const Time &t) const {
        // 计算两个时间之间的时间差，单位为小时。
        return (hour - t.hour) + (minute - t.minute) / 60.0;
    }

    int diffInMinutes(const Time &t) const {
        // 计算两个时间之间的时间差，单位为分钟。
        return (hour - t.hour) * 60 + (minute - t.minute);
    }

    string diffInHHMM(const Time &t) const {
        int diff_minutes = diffInMinutes(t);
        int hours = diff_minutes / 60;
        int minutes = abs(diff_minutes % 60);

        ostringstream oss;
        oss << setw(2) << setfill('0') << abs(hours) << ":"
            << setw(2) << setfill('0') << minutes;
        return oss.str();
    }

    friend istream &operator>>(istream &in, Time &time);

    friend ostream &operator<<(ostream &out, const Time &time);
};

istream &operator>>(istream &in, Time &time) {
    // 以 xx:xx 格式输入。
    char c;
    in >> time.hour >> c >> time.minute;
    return in;
}

ostream &operator<<(ostream &out, const Time &time) {
    // 以 xx:xx 格式输出。
    out << setfill('0') << setw(2) << time.hour << ":"
        << setfill('0') << setw(2) << time.minute;
    return out;
}

int main() {
    Time startTime, endTime;
    cout << "Please use the \"xx:xx format\"." << endl;
    cout << "Please enter the start time." << endl;
    cin >> startTime;
    cout << "Please enter the end time." << endl;
    cin >> endTime;

    cout << "Please select the output format:" << endl
         << "1: Output in hours;" << endl
         << "2: Output in minutes;" << endl
         << "3: Output in hh:mm." << endl;
    int mode = 0;
    cin >> mode;

    switch (mode) {
        case 1:
            cout << fixed << setprecision(2);
            cout << "The time interval is " << startTime.diffInHours(endTime) << " hours." << endl;
            break;
        case 2:
            cout << "The time interval is " << startTime.diffInMinutes(endTime) << " minutes." << endl;
            break;
        case 3:
            cout << "The time interval is " << startTime.diffInHHMM(endTime) << endl;
            break;
        default:
            cout << "Invalid option selected." << endl;
            break;
    }
    
    system("pause");
    return 0;
}
