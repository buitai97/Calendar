#pragma once
#include "MyScheduleDay.h"
#include <iostream>

class MyCalendar
{
	const string months[13] = { "unknown", "January", "February", "March" ,
"April", "May", "June", "July", "August", "September", "October" ,"November",
"December" };
private:
	unsigned short currentYear;
	unsigned short currentMonth;
	unsigned short currentDay;
	MyScheduleDay scheduleDays[12][31];
public:
	//Constructor
	MyCalendar();

	// setters
	void setCurrentYear(int newCurrentYear);
	void setCurrentMonth(int newCurrentMonth);
	void setCurrentDay(int newCurrentDay);
	void setCurrentYearMenu();
	void setCurrentMonthMenu();
	void setCurrentDayMenu();
	void setCurrentCalendarMenu();
	void jumpForward(int daysJump);
	void jumpBackward(int daysJump);

	//getters
	int getCurrentYear()const;
	int getCurrentDay() const;
	int getCurrentMonth() const;
	void getCurrentDate() const;
	//overload functions
	MyCalendar& operator++();
	MyCalendar operator++(int);

	MyCalendar& operator--();
	MyCalendar operator--(int);

	friend ostream& operator<<(ostream&, const MyCalendar& obj);
	
	// static functions
	
};
bool isLeap(const unsigned short year);
int getDaysInMonth(const int monthNumber, const int year);
string getDayInWeek(int day, int month, int year);
