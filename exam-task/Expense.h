#pragma once
#include <iostream>
#include <string>
#include "Date.h"
#include "Time.h"
#include "Category.h"
using namespace std;

class Expense
{
private:
	double amount;
	Category category;
	Date date;
	Time time;

public:
	Expense();
	Expense(double amount, Category category, Date date, Time time);
	Expense(double amount, string categoryName, double categoryCashback, unsigned short day, unsigned short month, unsigned short year, unsigned short seconds, unsigned short minutes, unsigned short hours);

	double getAmount() const;
	Category getCategory() const;
	Date getDate() const;
	Time getTime() const;

	string toString();

	void setAmount(double amount);
	void setCategory(Category category);
	void setDate(Date date);
	void setTime(Time time);

	bool operator<(const Expense &e) const;
	bool operator>(const Expense &e) const;

	friend ostream &operator<<(ostream &o, const Expense &e);
	friend istream &operator>>(istream &i, Expense &e);
};

Expense::Expense() : amount(0), category(Category()), date(Date()), time(Time()) {}

Expense::Expense(double amount, Category category, Date date, Time time) : amount(amount), category(category), date(date), time(time) {}

Expense::Expense(double amount, string categoryName, double categoryCashback, unsigned short day, unsigned short month, unsigned short year, unsigned short seconds, unsigned short minutes, unsigned short hours) : amount(amount), category(Category(categoryName, categoryCashback)), date(Date(day, month, year)), time(Time(seconds, minutes, hours)) {}

double Expense::getAmount() const
{
	return amount;
}

Category Expense::getCategory() const
{
	return category;
}

Date Expense::getDate() const
{
	return date;
}

Time Expense::getTime() const
{
	return time;
}

string Expense::toString()
{
	return "Expense:\nAmount: " + to_string(amount) + "\nCategory: " + category.toString() + "\nDate: " + date.toString() + "\nTime: " + time.toString();
}

void Expense::setAmount(double amount)
{
	this->amount = amount;
}

void Expense::setCategory(Category category)
{
	this->category = category;
}

void Expense::setDate(Date date)
{
	this->date = date;
}

void Expense::setTime(Time time)
{
	this->time = time;
}

bool Expense::operator<(const Expense &e) const
{
	return amount < e.amount;
}

bool Expense::operator>(const Expense &e) const
{
	return amount > e.amount;
}

ostream &operator<<(ostream &o, const Expense &e)
{
	o << "Expense:\n";
	o << "Amount: " << e.amount << "\n";
	o << "Category:\n"
	  << e.category << "\n";
	o << "Date: " << e.date << "\n";
	o << "Time: " << e.time;
	return o;
}

istream &operator>>(istream &i, Expense &e)
{
	cout << "New expense:\nAmount: ";
	i >> e.amount;
	cout << "Category: ";
	i >> e.category;
	i >> e.date;
	i >> e.time;

	return i;
}