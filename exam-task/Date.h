#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Date
{
private:
	unsigned short dateYear;
	unsigned short dateMonth;
	unsigned short dateDay;

public:
	Date();
	Date(unsigned short day, unsigned short month, unsigned short year);

	void Display() const;
	void Initialize();

	short GetDay() const;
	short GetMonth() const;
	short GetYear() const;

	void SetDay(unsigned short day);
	void SetMonth(unsigned short month);
	void SetYear(unsigned short year);

	bool IsLeap() const;
	int DaysInMonth() const;
	int DaysInYear() const;
	int DaysFromBeginning() const;
	string toString();
	string toString() const;

	bool operator==(const Date &d) const;
	bool operator>(const Date &d) const;
	bool operator<(const Date &d) const;
	Date operator-(const int days);
	bool operator<=(const Date &d) const;
	bool operator>=(const Date &d) const;
};

ostream &operator<<(ostream &o, const Date &d);
istream &operator>>(istream &i, Date &d);

Date::Date() : dateDay(0), dateMonth(0), dateYear(0) {}

Date::Date(unsigned short day, unsigned short month, unsigned short year) : dateDay(day), dateMonth(month), dateYear(year) {}

void Date::Display() const
{
	cout << setw(2) << setfill('0') << dateDay << "." << setw(2) << setfill('0') << dateMonth << "." << setw(2) << setfill('0') << dateYear << "\n";
}

void Date::Initialize()
{
	char dot1, dot2;
	cout << "Enter the date in the format dd.mm.yyyy: ";
	cin >> dateDay >> dot1 >> dateMonth >> dot2 >> dateYear;
	if (dot1 != '.' || dot2 != '.' || dateDay < 0 || dateMonth < 0 || dateMonth > 12 ||
		((dateMonth == 1 || dateMonth == 3 || dateMonth == 5 || dateMonth == 7 || dateMonth == 8 || dateMonth == 10 || dateMonth == 12) && dateDay > 31) ||
		((dateMonth == 4 || dateMonth == 6 || dateMonth == 9 || dateMonth == 11) && dateDay > 30) ||
		(dateMonth == 2 && dateYear % 4 != 0 && dateDay > 28) ||
		(dateMonth == 2 && dateYear % 4 == 0 && dateDay > 29))
	{
		system("cls");
		Initialize();
	}
}

short Date::GetDay() const
{
	return dateDay;
}

short Date::GetMonth() const
{
	return dateMonth;
}

short Date::GetYear() const
{
	return dateYear;
}

void Date::SetDay(unsigned short day)
{
	dateDay = day;
}

void Date::SetMonth(unsigned short month)
{
	dateMonth = month;
}

void Date::SetYear(unsigned short year)
{
	dateYear = year;
}

bool Date::IsLeap() const
{
	return (dateYear % 4 == 0 && dateYear % 100 != 0) || dateYear % 400 == 0;
}

int Date::DaysInYear() const
{
	return IsLeap() ? 366 : 365;
}

int Date::DaysInMonth() const
{
	if (dateMonth == 2)
		return IsLeap() ? 29 : 28;
	else if (dateMonth == 4 || dateMonth == 6 || dateMonth == 9 || dateMonth == 11)
		return 30;
	return 31;
}

int Date::DaysFromBeginning() const
{
	int tmp = 0;
	for (int y = 0; y < dateYear; y++)
		tmp += Date(1, 1, y).DaysInYear();
	for (int m = 1; m < dateMonth; m++)
		tmp += Date(1, m, dateYear).DaysInMonth();
	tmp += dateDay - 1;
	return tmp;
}

string Date::toString()
{
	return to_string(dateDay) + "." + to_string(dateMonth) + "." + to_string(dateYear);
}

string Date::toString() const
{
	return to_string(dateDay) + "." + to_string(dateMonth) + "." + to_string(dateYear);
}

bool Date::operator==(const Date &d) const
{
	return (dateDay == d.dateDay && dateMonth == d.dateMonth && dateYear == d.dateYear);
}

bool Date::operator<(const Date &b) const
{
	if (dateYear < b.dateYear)
	{
		return true;
	}
	else if (dateYear == b.dateYear)
	{
		if (dateMonth < b.dateMonth)
		{
			return true;
		}
		else if (dateMonth == b.dateMonth)
		{
			if (dateDay < b.dateDay)
			{
				return true;
			}
		}
	}

	return false;
}

bool Date::operator>(const Date &b) const
{
	if (dateYear > b.dateYear)
	{
		return true;
	}
	else if (dateYear == b.dateYear)
	{
		if (dateMonth > b.dateMonth)
		{
			return true;
		}
		else if (dateMonth == b.dateMonth)
		{
			if (dateDay > b.dateDay)
			{
				return true;
			}
		}
	}

	return false;
}

Date Date::operator-(const int days)
{
	Date tmp(this->dateDay, this->dateMonth, this->dateYear);
	dateDay -= days;
	if (((dateMonth == 1 || dateMonth == 3 || dateMonth == 5 || dateMonth == 7 || dateMonth == 8 || dateMonth == 10 || dateMonth == 12) && dateDay < 0))
	{
		dateDay += 31;
		dateMonth -= 1;
	}
	else if ((dateMonth == 4 || dateMonth == 6 || dateMonth == 9 || dateMonth == 11) && dateDay < 0)
	{
		dateDay += 30;
		dateMonth -= 1;
	}
	else if ((dateMonth == 2 && dateYear % 4 != 0 && dateDay < 0))
	{
		dateDay += 28;
		dateMonth -= 1;
	}
	else if ((dateMonth == 2 && dateYear % 4 == 0 && dateDay < 0))
	{
		dateDay += 29;
		dateMonth -= 1;
	}

	if (dateMonth < 1)
	{
		dateMonth = 12;
		dateYear -= 1;
	}

	return tmp;
}

bool Date::operator<=(const Date &d) const
{
	if (*this < d || *this == d)
	{
		return true;
	}

	return false;
}

bool Date::operator>=(const Date &d) const
{
	if (*this > d || *this == d)
	{
		return true;
	}

	return false;
}

ostream &operator<<(ostream &o, const Date &d)
{
	o << setw(2) << setfill('0') << d.GetDay() << "." << setw(2) << setfill('0') << d.GetMonth() << "." << setw(2) << setfill('0') << d.GetYear();
	return o;
}

istream &operator>>(istream &i, Date &d)
{
	char dot1, dot2;
	unsigned short day, month, year;
RETRY:
	cout << "Enter the date in the format dd.mm.yyyy: ";
	i >> day >> dot1 >> month >> dot2 >> year;
	if (dot1 != '.' || dot2 != '.' || day < 0 || month < 0 || month > 12 ||
		((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) ||
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) ||
		(month == 2 && year % 4 != 0 && day > 28) ||
		(month == 2 && year % 4 == 0 && day > 29))
	{
		system("cls");
		goto RETRY;
	}

	d.SetDay(day);
	d.SetMonth(month);
	d.SetYear(year);
	return i;
}