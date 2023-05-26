#pragma once
#include "Account.h"
#include "Expense.h"
#include <limits>
#include <string>
#include <vector>
using namespace std;

class Wallet : public Account
{
private:
	string walletName;
	double creditLimit;

public:
	Wallet();
	Wallet(string memberName, string accountNumber, double balance, string walletName, double creditLimit, vector<Expense> expenses);

	void deposit(double amount);
	void withdraw(double amount, Category expenseCategory, Date expenseDate, Time expenseTime);
	void show();

	vector<Expense> getAllExpenses();
	vector<Expense> getExpensesByCategory(Category category);

	friend ostream &operator<<(ostream &o, const Wallet &w);
	friend istream &operator>>(istream &i, Wallet &w);
};

Wallet::Wallet() : Account(), walletName("default"), creditLimit(0.0) {}

Wallet::Wallet(string memberName, string accountNumber, double balance, string walletName, double creditLimit, vector<Expense> expenses) : Account(memberName, accountNumber, balance, expenses), walletName(walletName), creditLimit(creditLimit) {}

void Wallet::deposit(double amount)
{
	balance += amount;
}

void Wallet::withdraw(double amount, Category expenseCategory, Date expenseDate, Time expenseTime)
{
	balance -= amount;
	if (balance < 0)
	{
		if (balance < creditLimit)
		{
			balance += amount;
			cout << "Expense is too big";
		}
	}

	balance += amount * (expenseCategory.getCategoryCashback() / 100);
	Expense tmp(amount, expenseCategory, expenseDate, expenseTime);
	expenses.push_back(tmp);
}

void Wallet::show()
{
	cout << "-----------------------------"
		 << "\n";
	cout << "Wallet " << walletName << ":"
		 << "\n";
	cout << " balance: " << balance << "\n";
	cout << " Credit limit: " << creditLimit << "\n";
	cout << "Holder: "
		 << "\n";
	cout << " Name: " << memberName << "\n";
	cout << " Wallet number: " << accountNumber << "\n";
	cout << "-----------------------------"
		 << "\n";
	;
}

vector<Expense> Wallet::getExpensesByCategory(Category category)
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

vector<Expense> Wallet::getAllExpenses()
{
	return expenses;
}

ostream &operator<<(ostream &o, const Wallet &w)
{
	o << "-----------------------------"
	  << "\n";
	o << "Wallet " << w.walletName << ":"
	  << "\n";
	o << " balance: " << w.balance << "\n";
	o << " Credit limit: " << w.creditLimit << "\n";
	o << "Holder: "
	  << "\n";
	o << " Name: " << w.memberName << "\n";
	o << " Wallet number: " << w.accountNumber << "\n";
	o << "-----------------------------";
	return o;
}

istream &operator>>(istream &i, Wallet &w)
{
	cout << "New wallet: "
		 << "\n";
	cout << " Account member: ";
	i.ignore();
	getline(i, w.memberName);

	cout << " Account number: ";
	getline(i, w.accountNumber);

	cout << " balance: ";
	i >> w.balance;

	cout << " Credit limit (if wallet is debit enter 0): ";
	i >> w.creditLimit;

	cout << " Wallet name: ";
	i.ignore();
	getline(i, w.walletName);

	vector<Expense> tmp;
	tmp.push_back(Expense());
	w.expenses = tmp;

	return i;
}