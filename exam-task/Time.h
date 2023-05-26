#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Time
{
private:
	unsigned short sec;
	unsigned short mins;
	unsigned short hr;

public:
	Time();
	Time(unsigned short seconds, unsigned short minutes, unsigned short hours);

	void display() const;
	void initialize();
	string toString();

	short getSeconds() const;
	short getMinutes() const;
	short getHours() const;

	void setSeconds(unsigned short seconds);
	void setMinutes(unsigned short minutes);
	void setHours(unsigned short hours);
};

ostream &operator<<(ostream &o, const Time &t);
istream &operator>>(istream &i, Time &t);

Time::Time() : sec(0), mins(0), hr(0) {}

Time::Time(unsigned short seconds, unsigned short minutes, unsigned short hours) : sec(seconds), mins(minutes), hr(hours) {}

void Time::display() const
{
	cout << setw(2) << setfill('0') << hr << ":" << setw(2) << setfill('0') << mins << ":" << setw(2) << setfill('0') << sec << "\n";
}

void Time::initialize()
{
	char colon1, colon2;
	cout << "Enter time in format hh:mm:ss: ";
	cin >> sec >> colon1 >> mins >> colon2 >> hr;
	if (colon1 != ':' || colon2 != ':' || sec < 0 || sec > 59 || mins < 0 || mins > 59 || hr < 0 || hr > 23)
	{
		system("cls");
		initialize();
	}
}

string Time::toString()
{
	return to_string(sec) + ":" + to_string(mins) + ":" + to_string(hr);
}

short Time::getSeconds() const
{
	return sec;
}

short Time::getMinutes() const
{
	return mins;
}

short Time::getHours() const
{
	return hr;
}

void Time::setSeconds(unsigned short seconds)
{
	sec = seconds;
}

void Time::setMinutes(unsigned short minutes)
{
	mins = minutes;
}

void Time::setHours(unsigned short hours)
{
	hr = hours;
}

ostream &operator<<(ostream &o, const Time &t)
{
	o << setw(2) << setfill('0') << t.getHours() << ":" << setw(2) << setfill('0') << t.getMinutes() << ":" << setw(2) << setfill('0') << t.getSeconds();
	return o;
}

istream &operator>>(istream &i, Time &t)
{
	char colon1, colon2;
	unsigned short seconds, minutes, hours;
INIT:
	cout << "Enter time in format hh:mm:ss: ";
	cin >> seconds >> colon1 >> minutes >> colon2 >> hours;
	if (colon1 != ':' || colon2 != ':' || seconds < 0 || seconds > 59 || minutes < 0 || minutes > 59 || hours < 0 || hours > 23)
	{
		system("cls");
		goto INIT;
	}

	t.setSeconds(seconds);
	t.setMinutes(minutes);
	t.setHours(hours);
	return i;
}