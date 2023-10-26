#pragma once
#include "MyUnit.h"
class MyScheduleDay : public MyUnit
{
private:
	char type;
public:
	// Constructor
	MyScheduleDay();
	// Setter
	void setType(const char newType);
	// Getter
	char getType() const;
	// Overload function
	friend ostream& operator<<(ostream& out, const MyScheduleDay& obj);
};

