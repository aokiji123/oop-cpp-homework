#pragma once
#include <vector>
#include <map>
#include <algorithm>
#include "Expense.h"
#include "Account.h"
#include "Date.h"
using namespace std;

class ReportGenerator
{
public:
	ReportGenerator();

	map<Date, vector<Expense>> generateDayReport(Date date, vector<Account *> &accounts);
	map<Date, vector<Expense>> generateWeekReport(Date date, vector<Account *> &accounts);
	map<Date, vector<Expense>> generateMonthReport(Date date, vector<Account *> &accounts);
};

ReportGenerator::ReportGenerator() {}

map<Date, vector<Expense>> ReportGenerator::generateDayReport(Date date, vector<Account *> &accounts)
{
	vector<Expense> report;
	int count = 0;
	for (int i = 0; i < accounts.size(); i++)
	{
		for (const auto &expense : accounts[i]->getAllExpenses())
		{
			if (expense.getDate() == date)
			{
				report.push_back(expense);
			}
		}
	}

	count = report.size();
	while (count > 0)
	{
		bool isSwapped = false;
		for (int i = 0; i < count - 1; i++)
		{
			if (report[i] > report[i + 1])
			{
				swap(report[i], report[i + 1]);
				isSwapped = true;
			}
		}

		if (!isSwapped)
			break;
		count--;
	}

	reverse(report.begin(), report.end());
	map<Date, vector<Expense>> resultReport;
	resultReport.insert(make_pair(date, report));
	return resultReport;
}

map<Date, vector<Expense>> ReportGenerator::generateWeekReport(Date date, vector<Account *> &accounts)
{
	vector<Expense> report;
	int count = 0;
	for (int i = 0; i < accounts.size(); i++)
	{
		for (const auto &expense : accounts[i]->getAllExpenses())
		{
			if (expense.getDate() >= date - 7 && expense.getDate() <= date)
			{
				report.push_back(expense);
			}
		}
	}

	count = report.size();
	while (count > 0)
	{
		bool isSwapped = false;
		for (int i = 0; i < count - 1; i++)
		{
			if (report[i] > report[i + 1])
			{
				swap(report[i], report[i + 1]);
				isSwapped = true;
			}
		}

		if (!isSwapped)
			break;
		count--;
	}

	reverse(report.begin(), report.end());
	map<Date, vector<Expense>> resultReport;
	resultReport.insert(make_pair(date, report));
	return resultReport;
}

map<Date, vector<Expense>> ReportGenerator::generateMonthReport(Date date, vector<Account *> &accounts)
{
	vector<Expense> report;
	int count = 0;
	for (int i = 0; i < accounts.size(); i++)
	{
		for (const auto &expense : accounts[i]->getAllExpenses())
		{
			if (expense.getDate().GetMonth() == date.GetMonth() &&
				expense.getDate().GetYear() == date.GetYear())
			{
				report.push_back(expense);
			}
		}
	}

	count = report.size();
	while (count > 0)
	{
		bool isSwapped = false;
		for (int i = 0; i < count - 1; i++)
		{
			if (report[i] > report[i + 1])
			{
				swap(report[i], report[i + 1]);
				isSwapped = true;
			}
		}

		if (!isSwapped)
			break;
		count--;
	}

	reverse(report.begin(), report.end());
	map<Date, vector<Expense>> resultReport;
	resultReport.insert(make_pair(date, report));
	return resultReport;
}