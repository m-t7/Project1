/*
* Name: Mark Turner
* Date: 9/17/2023
* Class: CS 210
*/


#include <iostream>
#include "Clock.h"
using namespace std;

string getCenteredText(string s, int width, char borderChar) {
    int spaces = (width - s.length()) / 2 - 1;
    string centeredText = borderChar + string(spaces, ' ') + s + string(spaces, ' ');

    // add extra spaces in case division does not return exact number of spaces needed
    while (centeredText.length() < width - 1) centeredText += ' ';

    // add closing border charactor
    return centeredText + borderChar;
}

void displayMenu() {
    int width = 23;
    string horizontalBorder(width, '*'); // top and bottom border for console menu 
    string option1 = "* 1 - Add One Hour";
    string option2 = "* 2 - Add One Minute";
    string option3 = "* 3 - Add One Second";
    string option4 = "* 4 - Exit Program";

    // output menu options
    cout << endl
        << horizontalBorder << endl
        << option1 << string(width - option1.length() - 1, ' ') << '*' << endl
        << option2 << string(width - option2.length() - 1, ' ') << '*' << endl
        << option3 << string(width - option3.length() - 1, ' ') << '*' << endl
        << option4 << string(width - option4.length() - 1, ' ') << '*' << endl
        << horizontalBorder << endl;
}

void displayClocks() {
    int width = 23;
    string horizontalBorder(width, '*'); // top and bottom border for clock display 
    string clock12Header = "12-Hour Clock";
    string clock24Header = "24-Hour Clock";

    cout << endl 
        << horizontalBorder << '\t'
        << horizontalBorder << endl
        << getCenteredText(clock12Header, width, '*') << '\t'
        << getCenteredText(clock24Header, width, '*') << endl
        << getCenteredText(get12HourTimeFormat(), width, '*') << '\t'
        << getCenteredText(get24HourTimeFormat(), width, '*') << endl
        << horizontalBorder << '\t'
        << horizontalBorder << endl;
}

// continuously prompt the user for a valid time until the input is considered valid. 
void handleInvalidTimeInput(int &integer, string timeType, int upperBound) {
    while (cin.fail() || integer < 0 || integer > upperBound) {
        cin.clear(); // Clear any errors on cin to allow the "cin.fail()" check to evaluate as false
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear all characters from the input stream up to a new line character
        cout << endl << "You've entered an invalid time value for " << timeType << "(s). Please enter an integer between 0 and " << upperBound << ": ";
        cin >> integer;
    }
}

// initialize the hour, minute, and seconds of the clock with inputs from the user
void initializeClock() {
    int hour;
    int minute;
    int second;

    cout << "Enter the current hour (in 24hr time format): ";
    cin >> hour;
    handleInvalidTimeInput(hour, "hour", 23);

    cout << "Enter the current minute(s): ";
    cin >> minute;
    handleInvalidTimeInput(hour, "minute", 59);

    cout << "Enter the current second(s): ";
    cin >> second;
    handleInvalidTimeInput(hour, "second", 59);

    setCurrentTime(hour, minute, second);
}

void main()
{
    initializeClock();
    
    // display visuals and handle user input
    char userInput;
    while (true) {
        displayClocks();
        displayMenu();
    
        cout << "\nPlease enter a valid menu option: ";
        cin >> userInput;
        system("cls");

        switch (userInput) {
            case '1':
                addHour();
                break;
            case '2':
                addMinute();
                break;
            case '3':
                addSecond();
                break;
            case '4':
                cout << "Program ended" << endl;
                return;
            default:
                cout << userInput << " is not a valid option! Please choose again." << endl;
                break;
        }
    }
}