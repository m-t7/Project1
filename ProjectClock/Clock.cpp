#include "Clock.h"
#include <format>
#include <string>

int currentHours; // hours are maintained in 24hr format and cannot exceed 23
int currentMinutes; // minutes cannot exceed 59
int currentSeconds; // seconds cannot exceed 59

void addHour() {
	if (currentHours < 23) {
		currentHours++;
	}
	else {
		currentHours = 0;
		addHour();
	}
}

void addMinute() {
	if (currentMinutes < 59) {
		currentMinutes++;
	}
	else {
		currentMinutes = 0;
		addHour();
	}
}

void addSecond() {
	if (currentSeconds < 59) {
		currentSeconds++;
	}
	else {
		currentSeconds = 0;
		addMinute();
	}
}

void setCurrentTime(int hours, int minutes, int seconds) {
	
	currentHours = hours;
	currentMinutes = minutes;
	currentSeconds = seconds;
}

std::string formatTwoDigitTime(int time) {
	std::string formattedTime = std::to_string(time);

	if (time < 10) formattedTime = "0" + formattedTime;

	return formattedTime;
}

std::string get12HourTimeFormat() {
	// Determine suffix based on the current hour being greater than 11 AM
	std::string suffix = currentHours > 11 ? "PM" : "AM";
	// Convert currentHour from 24hr format to 12hr based on the current hour being greater than 12 PM
	std::string current12Hr = currentHours > 12 ? formatTwoDigitTime(currentHours - 12) : formatTwoDigitTime(currentHours);
	std::string currentMin = formatTwoDigitTime(currentMinutes);
	std::string currentSec = formatTwoDigitTime(currentSeconds);
	std::string formattedTime = current12Hr + ":" + currentMin + ":" + currentSec + " " + suffix;

	return formattedTime;
}

std::string get24HourTimeFormat() {
	// CurrentHours are already maintained in 24hr format so there is no need for conversion
	std::string current24Hr = formatTwoDigitTime(currentHours);
	std::string currentMin = formatTwoDigitTime(currentMinutes);
	std::string currentSec = formatTwoDigitTime(currentSeconds);
	std::string formattedTime = current24Hr + ":" + currentMin + ":" + currentSec;

	return formattedTime;
}