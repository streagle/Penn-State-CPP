#include <iostream>
#include <iomanip>
#include <ctime>
#include <thread>

using namespace std;

int main()
{
    // Variables

    // setting up the time variables
    time_t timestamp = time(NULL);
    struct tm datetime = *localtime(&timestamp);

    char output[50];

    // Inputs

    // Processes
    strftime(output, 50, "%B %e, %Y", &datetime);

    cout << "Todays date is " << output << endl;
    int hour = datetime.tm_hour;
    string period = "AM";

    while (true) {
        // Update the time variables
        timestamp = time(NULL);
        datetime = *localtime(&timestamp);

        hour = datetime.tm_hour;
        period = "AM";

        if (hour >= 12) {
            period = "PM";
            if (hour > 12) {
                hour -= 12;
            }
        } else if (hour == 0) {
            hour = 12;
        }

        // Clear the console (platform-specific)
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        cout << "Todays date is " << output << endl;
        cout << "The time is " << hour << ":" << setfill('0') << setw(2) << datetime.tm_min << ":" << setfill('0') << setw(2) << datetime.tm_sec << " " << period << endl;

        // Wait for 60 seconds
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}
