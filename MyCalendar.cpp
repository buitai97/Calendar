#include "MyCalendar.h"  // Include the declaration of the MyCalendar class.
#include <fstream>       // Header file for file operations.
#include <iostream>      // Header file for input/output operations.
#include <chrono>        // Header file for time-related operations.

using namespace std;  // Using the standard namespace for convenience.

// Constructor for the MyCalendar class.
MyCalendar::MyCalendar()
{
    // Get the current time point.
    auto currentTime = std::chrono::system_clock::now();

    // Convert the current time point to a time_t.
    std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);

    // Set the time zone to Pacific Standard Time (PST).
    std::tm currentTimeStruct;
    localtime_s(&currentTimeStruct, &currentTimeT);

    // Extract and print date components.
    currentYear = currentTimeStruct.tm_year + 1900;
    currentMonth = currentTimeStruct.tm_mon + 1;
    currentDay = currentTimeStruct.tm_mday;
}

// Setter methods for updating the current year, month, and day.
void MyCalendar::setCurrentYear(int newCurrentYear)
{
    currentYear = newCurrentYear;
}

void MyCalendar::setCurrentMonth(int newCurrentMonth)
{
    currentMonth = newCurrentMonth;
}

void MyCalendar::setCurrentDay(int newCurrentDay)
{
    currentDay = newCurrentDay;
}

// Getter methods for retrieving the current year, month, and day.
int MyCalendar::getCurrentYear() const
{
    return currentYear;
}

int MyCalendar::getCurrentDay() const
{
    return currentDay;
}

// Display current date.
int MyCalendar::displayCurrentDate() const
{
    return currentDay;
}

int MyCalendar::getCurrentMonth() const
{
    return currentMonth;
}

// Method to print the current date with additional formatting.
void MyCalendar::printCurrentDate() const
{
    string date = "";
    string postfix;
    if (currentDay % 10 == 1)
        postfix = "st";
    else if (currentDay % 10 == 2)
        postfix = "nd";
    else if (currentDay % 10 == 3)
        postfix = "rd";
    else
        postfix = "th";
    cout << "\n\t" << getDayInWeek(currentDay, currentMonth, currentYear) << ", " << months[currentMonth] << " " << currentDay << "th, " << currentYear
        << "\n\t" << currentMonth << "/" << currentDay << "/" << currentYear << "\n";
}

// Overloaded pre-increment operator.
MyCalendar& MyCalendar::operator++()
{
    currentDay++;
    if (currentDay > getDaysInMonth(currentMonth, currentYear)) {
        currentDay = 1;
        currentMonth++;
        if (currentMonth == 12)
            currentYear++;
    }
    return *this;
}

// Overloaded post-increment operator.
MyCalendar MyCalendar::operator++(int)
{
    MyCalendar temp = *this;
    currentDay++;
    if (currentDay > getDaysInMonth(currentMonth, currentYear)) {
        currentDay = 1;
        currentMonth++;
        if (currentMonth == 12)
            currentYear++;
    }
    return temp;
}

// Overloaded pre-decrement operator.
MyCalendar& MyCalendar::operator--()
{
    currentDay--;
    if (currentDay < 1) {
        if (currentMonth == 1)
            currentYear--;
        currentMonth--;
        currentDay = getDaysInMonth(currentMonth, currentYear);
    }
    return *this;
}

// Overloaded post-decrement operator.
MyCalendar MyCalendar::operator--(int)
{
    MyCalendar temp = *this;
    currentDay--;
    if (currentDay < 1) {
        if (currentMonth == 1)
            currentYear--;
        currentMonth--;
        currentDay = getDaysInMonth(currentMonth, currentYear);
    }
    return temp;
}

// Method to set the current year via a menu.
void MyCalendar::setCurrentYearMenu()
{
    while (true) {
        system("cls");
        cout << "\tCurrent Year: " << currentYear << " - " << currentYear;
        cout << "\n\t" << string(60, char(205));

        cout << "\n\t1. Set current year";
        cout << "\n\t" << string(60, char(196));
        cout << "\n\t0. Return to Main Menu";
        cout << "\n\t" << string(60, char(205));

        int option;
        cout << "\nOption: ";
        cin >> option;

        switch (option) {
        case 1: {
            unsigned short newYear = 0;
            cout << "\nEnter a year (1...9999):";
            cin >> newYear;
            setCurrentYear(newYear);
            cout << "\n\tCurrent year set to " << newYear << endl;
            break;
        }
        case 0: {
            // Returning to the main menu
            return;
        }
        default:
            cout << "\nInvalid option. Please try again.";
        }
        system("pause");
    }
}

// Method to set the current month via a menu.
void MyCalendar::setCurrentMonthMenu()
{
    while (true) {
        system("cls");
        cout << "\tCurrent Month: " << currentMonth << " - " << currentMonth;
        cout << "\n\t" << string(60, char(205));

        cout << "\n\t1. Set current month";
        cout << "\n\t" << string(60, char(196));
        cout << "\n\t0. Return to Main Menu";
        cout << "\n\t" << string(60, char(205));

        int option;
        cout << "\nOption: ";
        cin >> option;

        switch (option) {
        case 1: {
            unsigned short newMonth = 0;
            cout << "\nEnter a month (1...12):";
            cin >> newMonth;
            setCurrentMonth(newMonth);
            cout << "\n\tCurrent month set to " << newMonth << endl;
            break;
        }
        case 0: {
            // Returning to the main menu
            return;
        }
        default:
            cout << "\nInvalid option. Please try again.";
        }
        system("pause");
    }
}

// Method to set the current day via a menu.
void MyCalendar::setCurrentDayMenu()
{
    while (true) {
        system("cls");
        cout << "\tCurrent Day: " << currentDay << " - " << currentDay;
        cout << "\n\t" << string(60, char(205));

        cout << "\n\t1. Set current Day";
        cout << "\n\t" << string(60, char(196));
        cout << "\n\t0. Return to Main Menu";
        cout << "\n\t" << string(60, char(205));

        int option;
        cout << "\nOption: ";
        cin >> option;

        switch (option) {
        case 1: {
            unsigned short newDay = 0;
            cout << "\nEnter a Day (1...31):";
            cin >> newDay;
            setCurrentMonth(newDay);
            cout << "\n\tCurrent Day set to " << newDay << endl;
            break;
        }
        case 0: {
            // Returning to the main menu
            return;
        }
        default:
            cout << "\nInvalid option. Please try again.";
        }
        system("pause");
    }
}

// Method to perform various calendar operations via a menu.
void MyCalendar::setCurrentCalendarMenu()
{
    while (true) {
        system("cls");
        printCurrentDate();
        cout << "\n\tMy Calendar Menu";
        cout << "\n";
        cout << "\n\t" << string(60, char(205));
        cout << "\n\t1. ++ (pre-increment)";
        cout << "\n\t2. ++ (post-increment)";
        cout << "\n\t3. Jump Forward(+n)";
        cout << "\n\t" << string(60, char(196));
        cout << "\n\t-1. -- (pre-decrement)";
        cout << "\n\t-2. -- (post-decrement)";
        cout << "\n\t-3. Jump Backward (-n)";
        cout << "\n\t" << string(60, char(196));
        cout << "\n\t0. Return";
        cout << "\n\t" << string(60, char(205));
        int option;
        cout << "\n\tOption: ";
        cin >> option;
        int daysJump = 0;
        switch (option) {
        case 1: {
            cout << "\n\tpre - increment : (++)\n\n";
            ++(*this);
            printCurrentDate();
        }
              break;
        case 2: {
            cout << "\n\tpost - increment : (++)\n\n";
            MyCalendar temp = (*this)++;
            temp.printCurrentDate();
        }
              break;
        case 3: {
            cout << "\n\tEnter an integer (n):";
            int daysJump;
            cin >> daysJump;
            (*this).jumpForward(daysJump);
        }
              break;
        case -1: {
            cout << "\n\tpre - decrement : (--)\n\n";
            --(*this);
            printCurrentDate();
        }
               break;
        case -2: {
            cout << "\n\tpost - decrement : (--)\n\n";
            MyCalendar temp = (*this)--;
            temp.printCurrentDate();
        }
        case -3: {
            cout << "\n\tEnter an integer (n):";
            int daysJump;
            cin >> daysJump;
            (*this).jumpBackward(daysJump);
        }
               break;
        case 0:
            return;

        default:
            cout << "\nInvalid option. Please try again.\n";
        }
        system("pause");
    }
}

// Method to set a schedule for a specific date via a menu.
void MyCalendar::setScheduleDateMenu()
{
    int tempMonth = currentMonth;
    int tempDay = currentDay;
    while (true) {
        system("cls");

        MyScheduleDay currentScheduleDay;
        cout << "\n\tmonth       : " << months[tempMonth];
        cout << "\n\tday         : " << tempDay;
        cout << "\n\ttype        : " << currentScheduleDay.getType();
        cout << "\n\tdescription : " << currentScheduleDay.getDescription();
        cout << "\n";
        cout << "\n\tSchedule Date";
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t1. Schedule a date";
        cout << "\n\t2. Unschedule a date";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t3. display year schedules";
        cout << "\n\t4. display month schedules";
        cout << "\n\t5. display day schedule";
        cout << "\n\t0. return";
        cout << "\n\t" << string(80, char(205));
        cout << "\nOption: ";
        int option;
        cin >> option;
        switch (option)
        {
        case 0:
            return;
        case 1: {
            cout << "\nSpecify a month (1...12) : ";
            cin >> tempMonth;
            cout << "\nSpecify a day (1...31) :";
            cin >> tempDay;
            cout << "\nEnter description: ";
            string newDescription = "";
            cin >> newDescription;
            currentScheduleDay.setDescription(newDescription);
            char newType;
            cout << "\nSpecify a type (R-return, A-Awareness H-holiday or P-personal) :";
            cin >> newType;
            currentScheduleDay.setType(newType);
            if (scheduleDays[currentMonth][currentDay].getValue() == 1) {
                cout << "WARNING: overwrite the existing scheduled date to \"Personal\"";
            }
            currentScheduleDay.setValue(1);
            scheduleDays[tempMonth][tempDay] = currentScheduleDay;
            cout << "\nSUCCESS: Date has sucessfully been scheduled.";
            cout << scheduleDays[tempMonth][tempDay];
        }
              break;
        default:
            break;
        }
        cout << "\n";
        system("pause");
    }
}

// Method to jump forward in the calendar by a specified number of days.
void MyCalendar::jumpForward(int daysJump)
{
    while ((daysJump + currentDay) > getDaysInMonth(currentMonth, currentYear)) {
        int tempDaysJump = getDaysInMonth(currentMonth, currentYear) - currentDay;
        currentDay = 0;
        currentMonth++;
        if (currentMonth > 12) {
            currentMonth = 1;
            currentYear++;
        }
        daysJump -= tempDaysJump;
    }
    currentDay += daysJump;
}

// Method to synchronize the calendar with the system date.
void MyCalendar::syncToSystemDate() {
    auto currentTime = std::chrono::system_clock::now();
    std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);
    std::tm currentTimeStruct;
    localtime_s(&currentTimeStruct, &currentTimeT);

    // Update the currentYear, currentMonth, and currentDay based on the system date
    currentYear = currentTimeStruct.tm_year + 1900;
    currentMonth = currentTimeStruct.tm_mon + 1;
    currentDay = currentTimeStruct.tm_mday;
}

// Method to jump backward in the calendar by a specified number of days.
void MyCalendar::jumpBackward(int daysJump)
{
    while ((currentDay - daysJump) < 0) {
        currentMonth--;
        if (currentMonth < 1) {
            currentMonth = 12;
            currentYear--;
        }
        currentDay = getDaysInMonth(currentMonth, currentYear);
        daysJump -= currentDay;
    }
    currentDay -= daysJump;
}

// Method to save the calendar state to a binary file.
void MyCalendar::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename + ".dat", std::ios::binary);

    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open the file for writing.\n";
        return;
    }

    // Save current date and other relevant information to the DAT file
    outFile.write(reinterpret_cast<const char*>(&currentYear), sizeof(currentYear));
    outFile.write(reinterpret_cast<const char*>(&currentMonth), sizeof(currentMonth));
    outFile.write(reinterpret_cast<const char*>(&currentDay), sizeof(currentDay));

    // Save other relevant information to the file if needed

    outFile.close();
    std::cout << "Calendar saved to DAT file successfully.\n";
}

void MyCalendar::restoreFromFile() {
    // Prompt the user to enter the filename to restore from
    std::string filename;
    std::cout << "Enter the filename to restore from: ";
    std::cin >> filename;

    // Open the DAT file for reading in binary mode
    std::ifstream inFile(filename + ".dat", std::ios::binary);

    // Check if the file was successfully opened
    if (!inFile.is_open()) {
        std::cerr << "Error: Unable to open the file for reading.\n";
        return;
    }

    // Read data from the DAT file and update the calendar
    inFile.read(reinterpret_cast<char*>(&currentYear), sizeof(currentYear));
    inFile.read(reinterpret_cast<char*>(&currentMonth), sizeof(currentMonth));
    inFile.read(reinterpret_cast<char*>(&currentDay), sizeof(currentDay));

    // Read other relevant information from the file if needed

    // Close the file after reading
    inFile.close();

    // Notify the user that the calendar has been successfully restored
    std::cout << "Calendar restored from DAT file successfully.\n";
}

// Overloaded ostream operator to print calendar information
ostream& operator<<(ostream& out, const MyCalendar& obj) {
    // Determine if the current year is a leap year
    string leap = "";
    if (isLeap(obj.getCurrentYear())) {
        leap = " - (leap)";
    }
    else
        leap = " - (non - leap)";

    // Print current year information
    out << "\n\t" << string(1, char(179)) << "Current year : " << obj.currentYear << leap << " | ";
    out << "\n\t" << string(80, char(196));

    // Print current month and awareness information
    out << "\n\t| Current month: " << obj.currentMonth << " - October                       |";
    out << "\n\t| Awareness    : Breast Cancer Month                                        |";
    out << "\n\t" << string(80, char(196));

    // Print current day and scheduling information
    out << "\n\t| Current day  : " << obj.currentDay << " - " << getDayInWeek(obj.currentDay, obj.currentMonth, obj.currentYear) << "                     |";
    out << "\n\t|              : unschedule                                                 |";
    out << "\n\t" << string(80, char(196));

    // Print days of the week and a placeholder for the days of the month
    out << "\n\t| Sunday |  Monday |  Tuesday | Wednesday | Thursday |   Friday  | Saturday |";
    out << "\n\t" << string(80, char(196));
    out << "\n\t|     1  |      2  |      3   |      4    |      5   |      6    |      7   |";
    out << "\n\t|     8  |      9  |     10   |     11    |     12   |     13    |     14   |";
    out << "\n\t|    15  |     16  |     17   |     18    |     19   |     20    |     21   |";
    out << "\n\t|    22  |     23  |     24   |     25    |     26   |     27    |     28   |";
    out << "\n\t|    29  |     30  |     31   |     ??    |     ??   |     ??    |     ??   |";
    out << "\n\t" << string(80, char(196));

    return out;
}

// Function to check if a given year is a leap year
bool isLeap(const unsigned short year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

// Function to get the number of days in a month for a given year
int getDaysInMonth(const int monthNumber, const int year) {
    const int daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (monthNumber == 2 && isLeap(year)) {
        return 29;
    }
    return daysInMonth[monthNumber];
}

// Function to get the day of the week for a given date using Zeller's formula
string getDayInWeek(int day, int month, int year) {
    string daysInWeek[7] = { "Monday", "Tuesday","Wednesday","Thursday", "Friday","Saturday","Sunday" };

    // Adjust the month and year for Zeller's formula
    if (month < 3) {
        month += 12;
        year--;
    }

    // Calculate Zeller's formula to determine the day of the week
    int K = year % 100;
    int J = year / 100;
    int h = (day + (13 * (month + 1) / 5) + K + (K / 4) + (J / 4) - 2 * J) % 7;
    int currentDay = (h + 5) % 7;

    // Zeller's formula returns 0 for Saturday, 1 for Sunday, 2 for Monday, ..., 6 for Friday
    return daysInWeek[currentDay];
}
