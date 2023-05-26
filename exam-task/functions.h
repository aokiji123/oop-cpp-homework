#pragma once
#include "includes.h"
using namespace std;

int diffBetweenDates(Date beginDate, Date endDate);

int menu();
int add();

void addCard(vector<Account *> &accounts);
void addWallet(vector<Account *> &accounts);

int list(vector<Account *> &accounts);
int actions(vector<Account *> &accounts, int number);

void replenishment(Account *account);
void addExpense(Account *account);

int reports();
int ratings();

Date dayReport();
Date weekReport();
Date monthReport();

int ByPriceOrByCategory();
int reportActions();

int diffBetweenDates(Date beginDate, Date endDate)
{
	return endDate.DaysFromBeginning() - beginDate.DaysFromBeginning();
}

int menu()
{
	system("cls");
	int choice;

	cout << "Bank system"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "1. Show all cards and wallets"
		 << "\n";
	cout << "2. Add a new card"
		 << "\n";
	cout << "3. Exit"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "Enter your choice: ";
	cin >> choice;

	return choice;
}

int add()
{
	system("cls");
	int choice;

	cout << "Bank system"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "What do you want to add?"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "1. Card"
		 << "\n";
	cout << "2. Wallet"
		 << "\n";
	cout << "3. Exit"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "Enter your choice: ";
	cin >> choice;

	return choice;
}

void addCard(vector<Account *> &accounts)
{
	system("cls");
	Card newCard;

	cout << "Bank system"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cin >> newCard;
	accounts.push_back(new Card(newCard));
	Sleep(1000);
	system("cls");
	cout << "New card added!"
		 << "\n";
	cout << "Please wait 3 seconds..."
		 << "\n";
	Sleep(3000);

	system("cls");
}

void addWallet(vector<Account *> &accounts)
{
	system("cls");
	Wallet newWallet;
	cout << "Bank system"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cin >> newWallet;
	accounts.push_back(new Wallet(newWallet));
	Sleep(1000);
	system("cls");
	cout << "New wallet added!"
		 << "\n";
	cout << "Please wait 3 seconds..."
		 << "\n";
	Sleep(3000);
	system("cls");
}

int list(vector<Account *> &accounts)
{
	system("cls");
	if (accounts.size() == 0)
	{
		cout << "Bank system"
			 << "\n";
		cout << "-----------------------------"
			 << "\n";
		cout << "There are no wallets or cards "
			 << "\n";
		cout << "Please wait 3 seconds..."
			 << "\n";
		Sleep(3000);
		return 0;
	}

	int choice;

	cout << "Bank system"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "Which wallet or card do you want to work with?"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	for (int i = 0; i < accounts.size(); i++)
	{
		cout << i + 1 << ".";
		accounts[i]->show();
	}

	cout << "Enter your choice (0 to exit): ";
	cin >> choice;
	return choice;
}

int actions(vector<Account *> &accounts, int number)
{
	system("cls");
	int choice;

	cout << "Bank system"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	accounts[number - 1]->show();
	cout << "What do you want to do?"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "1. Replenishment"
		 << "\n";
	cout << "2. Add an expense"
		 << "\n";
	cout << "3. Generate a report"
		 << "\n";
	cout << "4. Generate a rating"
		 << "\n";
	cout << "5. Exit"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "Enter your choice: ";

	cin >> choice;
	return choice;
}

void replenishment(Account *account)
{
	system("cls");
	int sum;

	cout << "Bank system"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "How much money do you want to deposit into your account?"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "Enter the amount: ";
	cin >> sum;
	system("cls");
	cout << "Please wait 2 seconds..."
		 << "\n";
	account->deposit(sum);
	Sleep(2000);
}

void addExpense(Account *account)
{
	system("cls");
	Expense expense;

	cout << "Bank system"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cin >> expense;
	cout << "-----------------------------"
		 << "\n";
	system("cls");
	cout << "Please wait 2 seconds..."
		 << "\n";
	account->withdraw(expense.getAmount(), expense.getCategory(), expense.getDate(), expense.getTime());
	Sleep(2000);
}

int reports()
{
	system("cls");
	int choice;

	cout << "Bank system"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "What do you want to do?"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "1. Daily report generating"
		 << "\n";
	cout << "2. Weekly report generating"
		 << "\n";
	cout << "3. Monthly report generating"
		 << "\n";
	cout << "4. Exit"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "Enter your choice: ";

	cin >> choice;
	return choice;
}

int ratings()
{
	system("cls");
	int choice;

	cout << "Bank system"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "What do you want to do?"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "1. Show weekly ratings"
		 << "\n";
	cout << "2. Show monthly ratings"
		 << "\n";
	cout << "3. Add weekly ratings"
		 << "\n";
	cout << "4. Add monthly ratings"
		 << "\n";
	cout << "5. Exit"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "Enter your choice: ";

	cin >> choice;
	return choice;
}

Date dayReport()
{
	system("cls");

	cout << "Bank system"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "Day Report (enter the date)"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	Date date;
	cin >> date;

	return date;
}

Date weekReport()
{
	system("cls");

	cout << "Bank system"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "Week Report (enter the end date)"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	Date endDate;
	cin >> endDate;

	return endDate;
}

Date monthReport()
{
	system("cls");

	cout << "Bank system"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "Month Report (enter the date)"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	Date date;
	cin >> date;

	return date;
}

int ByPriceOrByCategory()
{
	system("cls");
	int choice;

	cout << "Bank system"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "Which rating do you want to generate?"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "1. By Price"
		 << "\n";
	cout << "2. By Category"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "Enter your choice: ";
	cin >> choice;

	return choice;
}

int reportActions()
{
	system("cls");
	int choice;

	cout << "Bank system"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "What do you want to do?"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "1. show the report"
		 << "\n";
	cout << "2. Add the report to a file"
		 << "\n";
	cout << "-----------------------------"
		 << "\n";
	cout << "Enter your choice: ";
	cin >> choice;

	return choice;
}