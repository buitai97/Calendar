#include "MyCalendar.h"
MyCalendar::MyCalendar()
{
    auto currentTime = std::chrono::system_clock::now();

    // Convert the current time point to a time_t
    std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);

    // Set the time zone to Pacific Standard Time (PST)
    std::tm currentTimeStruct;
    localtime_s(&currentTimeStruct, &currentTimeT);

    // Extract and print date components
	currentYear = currentTimeStruct.tm_year + 1900;
	currentMonth = currentTimeStruct.tm_mon + 1;
	currentDay = currentTimeStruct.tm_mday;
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
	return currentDay;
}

int MyCalendar::getCurrentMonth() const
{
	return currentMonth;
}

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
    cout << "\n\t" << getDayInWeek(currentDay, currentMonth, currentYear) << ", " << months[currentMonth]<< " "<<currentDay << "th, " << currentYear 
         << "\n\t" << currentMonth << "/" << currentDay << "/" << currentYear << "\n";
}

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
        case -1:{
            cout << "\n\tpre - decrement : (--)\n\n";
            --(*this);
            printCurrentDate();
        }
            break;
        case -2:{
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

void MyCalendar::jumpBackward(int daysJump)
{
    while ((currentDay - daysJump) < 0){
        int tempDaysJump = currentDay;
        currentMonth--;
        currentDay = getDaysInMonth(currentMonth, currentYear);
        if (currentMonth < 1) {
            currentMonth = 12;
            currentYear--;
        }
        daysJump -= tempDaysJump;
    }
    currentDay -= daysJump;
}

ostream& operator<<(ostream& out, const MyCalendar& obj)
{
    string leap = "";
    if (isLeap(obj.getCurrentYear())) {
        leap = " - (leap)";
    }
    else
        leap = " - (non - leap)";
    out << "\n\t" << string(1, char(179)) << "Current year : " << obj.currentYear << leap << " | ";
    out << "\n\t" << string(80, char(196));
    out << "\n\t| Current month: " << obj.currentMonth << " - October                       |";
    out << "\n\t| Awareness    : Breast Cancer Month                                        |";
    out << "\n\t" << string(80, char(196));
    out << "\n\t| Current day  : " << obj.currentDay << " - "<< getDayInWeek(obj.currentDay, obj.currentMonth, obj.currentYear) << "                     |";
    out << "\n\t|              : unschedule                                                 |";
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

bool isLeap(const unsigned short year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int getDaysInMonth(const int monthNumber, const int year)
{
    const int daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (monthNumber == 2 && isLeap(year)) {
        return 29;
    }
    return daysInMonth[monthNumber];
}
string getDayInWeek(int day, int month, int year) {
    string daysInWeek[7] = { "Monday", "Tuesday","Wednesday","Thursday", "Friday","Saturday","Sunday" };
    if (month < 3) {
        month += 12;
        year--;
    }
    int K = year % 100;
    int J = year / 100;

    int h = (day + (13 * (month + 1) / 5) + K + (K / 4) + (J / 4) - 2 * J) % 7;

    // Zeller's formula returns 0 for Saturday, 1 for Sunday, 2 for Monday, ..., 6 for Friday
    int currentDay  = (h + 5) % 7;
    return daysInWeek[currentDay];
}