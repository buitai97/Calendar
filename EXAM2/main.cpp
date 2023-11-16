// Name : Dang Tai Bui
// EXAM 2
// November 12, 2023

#include <iostream>
#include "MyCalendar.h"
#include "MyScheduleDay.h"
#include <iomanip>  
#include <ctime>
#include "input.h"

using namespace std;
char menuOption();
int main() {
    cout << "\n\t" << string(80, char(196));
    MyCalendar calendar;
    char option;
    do {
        system("cls");
        cout << calendar;
        option = menuOption();
        
        switch (toupper(option)) {
        case 'A':
            calendar.setCurrentYearMenu();
            break;
        case 'B':
            calendar.setCurrentMonthMenu();
            break;
        case 'C':
            calendar.setCurrentDayMenu();
            break;
        case 'D':
            calendar.setCurrentCalendarMenu();
            break;
        case 'E':
            calendar.setScheduleDateMenu();
            break;
        case 'G':
            calendar.saveToFile();
            system("pause");
            break;
        case 'H':
            calendar.restoreFromFile();
            break;
        case 'X':
            exit(0);
            break;
        default:
            cout << "\nInvalid option. Please try again.";
            break;
        }
        system("pause");
    } while (option != 'X');
    return 0;
}

char menuOption(){
    cout << "\n\t\nCMPR121 Exam2: MyCalendar - OOP implementations by Dang Tai Bui";
    cout << "\n\t" << string(80, char(205));
    cout << "\n\tA. Setting Current Year" ;
    cout << "\n\tB. Setting Current Month";
    cout << "\n\tC. Setting Current Day";
    cout << "\n\tD. Setting Current Calendar";
    cout << "\n\tE. Schedule and Report Dates";
    cout << "\n\t" << string(80, char(196));
    cout << "\n\tF. Sync to system's date" ;
    cout << "\n\tG. Save calendar to file";
    cout << "\n\tH. Restore calendar from file" ;
    cout << "\n\t" << string(80, char(196));
    cout << "\n\tX. Exit";
    cout << "\n\t" << string(80, char(205));

    return inputChar("\nOption: ");
}
