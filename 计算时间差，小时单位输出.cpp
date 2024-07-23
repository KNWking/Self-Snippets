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

    double operator-(const Time &t) const {
        // 计算两个时间之间的时间差，单位为小时。
        return (hour - t.hour) + (minute - t.minute) / 60.0;
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
    Time start_time, end_Time;
    cout << "Please use the \"xx:xx format\"." << endl;
    cout << "Please enter the start time." << endl;
    cin >> start_time;
    cout << "Please enter the end time." << endl;
    cin >> end_Time;
    double time_diff = end_Time - start_time;
    cout << fixed << setprecision(2);
    cout << "The time interval is " << time_diff << " hours." << endl;
    system("pause");
    return 0;
}
