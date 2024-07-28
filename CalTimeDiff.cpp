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

    double static diffInHours(const Time &startTime, const Time &endTime) {
        // 计算两个时间之间的时间差，单位为小时。
        return (endTime.hour - startTime.hour) + (endTime.minute - startTime.minute) / 60.0;
    }

    int static diffInMinutes(const Time &startTime, const Time &endTime) {
        // 计算两个时间之间的时间差，单位为分钟。
        return (endTime.hour - startTime.hour) * 60 + (endTime.minute - startTime.minute);
    }

    string static diffInHHMM(const Time &startTime, const Time &endTime) {
        // 计算两个时间之间的时间差，返回格式为 hh:mm。
        // TODO: 尝试处理结果为负的情况。
        int diff_minutes = diffInMinutes(startTime, endTime);
        int hours = diff_minutes / 60;
        int minutes = abs(diff_minutes) % 60;

        ostringstream oss;
        if (hours < 0) {
            oss << "-";
            hours = abs(hours);
        }
        oss << setfill('0') << setw(2) << hours << ":"
            << setfill('0') << setw(2) << minutes;
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
            cout << "The time interval is " << Time::diffInHours(startTime, endTime) << " hours." << endl;
            break;
        case 2:
            cout << "The time interval is " << Time::diffInMinutes(startTime, endTime) << " minutes." << endl;
            break;
        case 3:
            cout << "The time interval is " << Time::diffInHHMM(startTime, endTime) << endl;
            break;
        default:
            cout << "Invalid option selected." << endl;
            break;
    }

    system("pause");
    return 0;
}
