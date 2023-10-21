#include "Clock.h"
#include <format>

std::string formatTwoDigitTime(int time) {
	std::string formattedTime = std::to_string(time);

	if (time < 10) formattedTime = "0" + formattedTime;

	return formattedTime;
}