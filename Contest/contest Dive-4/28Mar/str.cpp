#include <iostream>
#include <sstream>
#include<bits/stdc++.h>
using namespace std;
std::string convertTo12HourFormat(const std::string& time24) {
    std::istringstream iss(time24);
    int hours, minutes;
    char colon;
    iss >> hours >> colon >> minutes;

    std::string period = (hours < 12) ? "AM" : "PM";
    if (hours == 0) {
        hours = 12;
    } else if (hours > 12) {
        hours -= 12;
    }

    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2) << std::setfill('0') << minutes << " " << period;
    return oss.str();
}

int main() {
    std::string time24;
    cin>>time24;
    std::string time12 = convertTo12HourFormat(time24);

    std::cout << "Time in 12-hour format: " << time12 << std::endl;

    return 0;
}