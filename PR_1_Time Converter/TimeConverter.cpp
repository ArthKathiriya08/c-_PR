#include <iostream>
using namespace std;

// Class for converting time formats
class TimeConverter
{

private:
    // Data members
    int hours, minutes, seconds, totalSeconds;

public:
    // Function to convert total seconds into HH:MM:SS format
    void secondsToTime()
    {
        cout << endl << "1. Second to time." << endl;
        cout << "Enter total seconds: ";
        cin >> totalSeconds;

        // Calculate hours, minutes, and seconds
        hours = totalSeconds / 3600;
        minutes = (totalSeconds % 3600) / 60;
        seconds = totalSeconds % 60;

        // Display converted time
        cout << endl
             << "Time = "
             << hours << ":"
             << minutes << ":"
             << seconds << endl
             << endl;
    }

    // Function to convert HH:MM:SS into total seconds
    void timeToSeconds()
    {
        cout << "2. Time to Seconds." << endl;

        // Take time input from user
        cout << "Enter hours: ";
        cin >> hours;

        cout << "Enter minutes: ";
        cin >> minutes;

        cout << "Enter seconds: ";
        cin >> seconds;

        // Calculate total seconds
        totalSeconds = (hours * 3600) + (minutes * 60) + seconds;

        // Display total seconds
        cout << endl
             << "Total Seconds = " << totalSeconds  << endl << endl;
    }
};

int main()
{
    // Create object of TimeConverter class
    TimeConverter time;

    // Call functions
    time.secondsToTime();
    time.timeToSeconds();

    return 0;
}