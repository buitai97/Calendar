#include "MyCalendar.h"
MyCalendar::MyCalendar()
{
	currentYear = 0;
	currentMonth = 0;
	currentDay = 0;
}

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

int MyCalendar::getCurrentYear() const
{
	return currentYear;
}

int MyCalendar::getCurrentDay() const
{
	return currentMonth;
}

int MyCalendar::getCurrentMonth() const
{
	return currentDay;
}

bool MyCalendar::isLeap(unsigned short year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

void MyCalendar::setCurrentYearMenu() {
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

void MyCalendar::setCurrentMonthMenu() {
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

void MyCalendar::setCurrentDayMenu() {
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

void MyCalendar::setCurrentCalendarMenu()
{
    while (true) {
        system("cls");
        cout << "\tWednesday, October 25th, 2023";
        cout << "\n\t10/25/2023";
        cout << "\n\tMy Calendar Menu";
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
        switch (option) {
        case 1:
            // Add code to set the current year here

            cout << "\nCurrent month to Twenty Fifth\n";
            break;
        case 0:
            return;
        default:
            cout << "\nInvalid option. Please try again.\n";
        }
    }
}


ostream& operator<<(ostream& out, const MyCalendar& obj)
{
    out << "\n\t" << string(80, char(196));
    out << "\n\t" << string(1, char(179)) << "Current year : " << obj.currentYear << " - (non - leap) | ";
    out << "\n\t" << string(80, char(196));
    out << "\n\t| Current month: " << obj.currentMonth << " - October                                              |";
    out << "\n\t| Awareness    : Breast Cancer Month                                       |";
    out << "\n\t" << string(80, char(196));
    out << "\n\t| Current day  : " << obj.currentDay << " - Saturday | ";
    out << "\n\t|              : unschedule                                                |";
    out << "\n\t" << string(80, char(196));
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
