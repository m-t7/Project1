#include <string>

void addHour();
void addMinute();
void addSecond();
void setCurrentTime(int hours, int minutes, int seconds);
std::string get12HourTimeFormat();
std::string get24HourTimeFormat();
std::string formatTwoDigitTime(int time);