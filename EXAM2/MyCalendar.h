#pragma once
#include "MyScheduleDay.h"
#include <iostream>

class MyCalendar
{
	const int daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
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
	
	//getters
	int getCurrentYear()const;
	int getCurrentDay() const;
	int getCurrentMonth() const;

	//overload functions
	friend ostream& operator<<(ostream&, const MyCalendar& obj);

	// Util functions
	static bool isLeap(unsigned short year);
};

