﻿// Name : Gary Bennet Samuel
// EXAM 2
// OCTOBER 29, 2023

#include <iostream>
#include "MyCalendar.h"
#include "MyScheduleDay.h"
#include <iomanip>  
#include "input.h"


using namespace std;

char menuOption();
//void setCurrentMonthMenu();
//void setCurrentDayMenu();
//void setCurrentCalendarMenu();
//void setReportandScheduleMenu();


int main() {
    MyCalendar calendar;
    char option;
    do {
        system("cls");
        cout << calendar;
        option = menuOption();
        
        switch (option) {
        case 'a':
        case 'A':
            calendar.setCurrentYearMenu();
            break;
        case 'b':
        case 'B':
            calendar.setCurrentMonthMenu();
            break;
        case 'c':
        case 'C':
            calendar.setCurrentDayMenu();
            break;
        case 'd':
        case 'D':
            calendar.setCurrentCalendarMenu();
        case 'x':
        case 'X':
            exit(0);
            break;
        default:
            cout << "\nInvalid option. Please try again.";
            break;
        }
    } while (option != 'x' && option != 'X');
    
    return 0;
}

char menuOption(){
    cout << "\n\t\nCMPR121 Exam2: MyCalendar - OOP implementations by Prof Q (10/2/2023)";
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