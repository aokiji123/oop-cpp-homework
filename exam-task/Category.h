#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Category
{
private:
	string categoryName;
	double categoryCashback;

public:
	Category();
	Category(string name, double cashback);

	string getCategoryName() const;
	double getCategoryCashback() const;
	string toString();
	bool operator==(const Category &c) const;
	bool operator!=(const Category &c) const;
};

ostream &operator<<(ostream &o, const Category &c);
istream &operator>>(istream &i, Category &c);

Category::Category() : categoryName("default"), categoryCashback(0.0) {}

Category::Category(string categoryName, double categoryCashback) : categoryName(categoryName), categoryCashback(categoryCashback) {}

string Category::getCategoryName() const
{
	return categoryName;
}

double Category::getCategoryCashback() const
{
	return categoryCashback;
}

string Category::toString()
{
	return "Category name: " + categoryName + "\nCategory cashback: " + to_string(categoryCashback);
}

bool Category::operator==(const Category &c) const
{
	return categoryName == c.getCategoryName();
}

bool Category::operator!=(const Category &c) const
{
	return categoryName != c.getCategoryName();
}

ostream &operator<<(ostream &o, const Category &c)
{
	o << "Category: " << c.getCategoryName() << "\nCashback: " << c.getCategoryCashback();
	return o;
}

istream &operator>>(istream &i, Category &c)
{
	string categoryName;
	double categoryCashback;

	cout << "Enter category name: ";
	i >> categoryName;
	cout << "Enter category cashback: ";
	i >> categoryCashback;

	c = Category(categoryName, categoryCashback);

	return i;
}