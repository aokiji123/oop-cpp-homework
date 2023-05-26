#pragma once
#include "Account.h"
#include "Expense.h"
#include <limits>
#include <string>
#include <vector>

class Card : public Account
{
private:
	string cardName;
	double creditLimit;

public:
	Card();
	Card(string memberName, string accountNumber, double balance, string cardName, double creditLimit, vector<Expense> expenses);

	void deposit(double amount);
	void withdraw(double amount, Category expenseCategory, Date expenseDate, Time expenseTime);
	void show();
	vector<Expense> getExpensesByCategory(Category category);
	vector<Expense> getAllExpenses();
	friend ostream &operator<<(ostream &o, const Card &c);
	friend istream &operator>>(istream &i, Card &c);
};

Card::Card() : Account(), cardName("default"), creditLimit(0.0) {}

Card::Card(string memberName, string accountNumber, double balance, string cardName, double creditLimit, vector<Expense> expenses) : Account(memberName, accountNumber, balance, expenses), cardName(cardName), creditLimit(creditLimit) {}

void Card::deposit(double amount)
{
	balance += amount;
}

void Card::withdraw(double amount, Category expenseCategory, Date expenseDate, Time expenseTime)
{
	balance -= amount;
	if (balance < 0)
	{
		if (balance < creditLimit)
		{
			balance += amount;
			cout << "Withdrawal amount exceeds credit limit";
		}
	}

	balance += amount * (expenseCategory.getCategoryCashback() / 100);
	Expense tmp(amount, expenseCategory, expenseDate, expenseTime);
	expenses.push_back(tmp);
}

void Card::show()
{
	cout << "-----------------------------"
		 << "\n";
	cout << "Card name: " << cardName << "\n";
	cout << "Current balance: " << balance << "\n";
	cout << "Credit limit: " << creditLimit << "\n";
	cout << "Account member information: "
		 << "\n";
	cout << "Account member name: " << memberName << "\n";
	cout << "Account number: " << accountNumber << "\n";
	cout << "-----------------------------"
		 << "\n";
}

vector<Expense> Card::getExpensesByCategory(Category category)
{
	vector<Expense> tmp;
	for (int i = 0; i < expenses.size(); i++)
	{
		if (expenses[i].getCategory() == category)
		{
			tmp.push_back(expenses[i]);
		}
	}

	return tmp;
}

vector<Expense> Card::getAllExpenses()
{
	return expenses;
}

ostream &operator<<(ostream &o, const Card &card)
{
	o << "-----------------------------"
	  << "\n";
	o << "Card name: " << card.cardName << "\n";
	o << "Current balance: " << card.balance << "\n";
	o << "Credit limit: " << card.creditLimit << "\n";
	o << "Account member information: "
	  << "\n";
	o << "Account member name: " << card.memberName << "\n";
	o << "Account number: " << card.accountNumber << "\n";
	o << "-----------------------------";
	return o;
}

istream &operator>>(istream &i, Card &card)
{
	cout << "Creating a new card: "
		 << "\n";
	cout << " Account member name: ";
	i.ignore();
	getline(i, card.memberName);

	cout << " Account number: ";
	getline(i, card.accountNumber);

	cout << " Current balance: ";
	i >> card.balance;

	cout << " Credit limit: ";
	i >> card.creditLimit;

	cout << " Card name: ";
	i.ignore();
	getline(i, card.cardName);

	vector<Expense> tmp;
	tmp.push_back(Expense());
	card.expenses = tmp;

	return i;
}