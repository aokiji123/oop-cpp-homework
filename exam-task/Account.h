#pragma once
#include <iostream>
#include "Expense.h"
#include "Time.h"
using namespace std;

class Account
{
protected:
	string memberName;
	string accountNumber;
	vector<Expense> expenses;
	double balance;

public:
	Account();
	Account(string memberName, string accountNumber, double balance, vector<Expense> expenses);

	virtual void deposit(double amount) = 0;
	virtual void withdraw(double amount, Category expenseCategory, Date expenseDate, Time expenseTime) = 0;
	virtual void show() = 0;
	virtual vector<Expense> getAllExpenses() = 0;
};

Account::Account() : memberName("default"), accountNumber("AA00 AAAA 0000 0000 0000 0000"), balance(0.0)
{
	vector<Expense> tmp;
	tmp.push_back(Expense());
	expenses = tmp;
}

Account::Account(string memberName, string accountNumber, double balance, vector<Expense> expenses) : memberName(memberName), accountNumber(accountNumber), balance(balance), expenses(expenses) {}