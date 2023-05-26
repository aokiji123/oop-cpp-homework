#pragma once
#include "ReportGenerator.h"
#include "Expense.h"
#include "Date.h"
#include <fstream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

class Report
{
private:
	map<Date, vector<Expense>> report;

public:
	Report(map<Date, vector<Expense>> report);

	void showDayReport(ReportGenerator rp, Date date, vector<Account *> &accounts);
	void showWeekReport(ReportGenerator rp, Date date, vector<Account *> &accounts);
	void showMonthReport(ReportGenerator rp, Date date, vector<Account *> &accounts);

	void addToFileDayReport(ReportGenerator rp, Date date, vector<Account *> &accounts);
	void addToFileWeekReport(ReportGenerator rp, Date date, vector<Account *> &accounts);
	void addToFileMonthReport(ReportGenerator rp, Date date, vector<Account *> &accounts);

	void showWeekRatingByPrice(ReportGenerator rp, Date date, vector<Account *> &accounts);
	void showMonthRatingByPrice(ReportGenerator rp, Date date, vector<Account *> &accounts);
	void showWeekRatingByCategory(ReportGenerator rp, Date date, vector<Account *> &accounts);
	void showMonthRatingByCategory(ReportGenerator rp, Date date, vector<Account *> &accounts);

	void addToFileWeekRatingByPrice(ReportGenerator rp, Date date, vector<Account *> &accounts);
	void addToFileMonthRatingByPrice(ReportGenerator rp, Date date, vector<Account *> &accounts);
	void addToFileWeekRatingByCategory(ReportGenerator rp, Date date, vector<Account *> &accounts);
	void addToFileMonthRatingByCategory(ReportGenerator rp, Date date, vector<Account *> &accounts);
};

Report::Report(map<Date, vector<Expense>> report) : report(report) {}

void Report::showDayReport(ReportGenerator rp, Date date, vector<Account *> &accounts)
{
	report = rp.generateDayReport(date, accounts);
	for (auto el : report)
	{
		for (int i = 0; i < el.second.size(); i++)
		{
			cout << "Day report: "
				 << "\n";
			cout << "Date: " << el.first << "\n";
			cout << "Info: "
				 << "\n";
			cout << el.second[i] << "\n";
			;
		}
	}
}

void Report::showWeekReport(ReportGenerator rp, Date date, vector<Account *> &accounts)
{
	report = rp.generateWeekReport(date, accounts);
	for (auto el : report)
	{
		for (int i = 0; i < el.second.size(); i++)
		{
			cout << "Day report: "
				 << "\n";
			cout << "Date: " << el.first << "\n";
			cout << "Info: "
				 << "\n";
			cout << el.second[i] << "\n";
			;
		}
	}
}

void Report::showMonthReport(ReportGenerator rp, Date date, vector<Account *> &accounts)
{
	report = rp.generateMonthReport(date, accounts);
	for (auto el : report)
	{
		for (int i = 0; i < el.second.size(); i++)
		{
			cout << "Day report: "
				 << "\n";
			cout << "Date: " << el.first << "\n";
			cout << "Info: "
				 << "\n";
			cout << el.second[i] << "\n";
			;
		}
	}
}

void Report::addToFileDayReport(ReportGenerator rp, Date date, vector<Account *> &accounts)
{
	report = rp.generateDayReport(date, accounts);
	string result;
	for (auto &pair : report)
	{
		result += pair.first.toString() + ":\n";
		for (auto &expense : pair.second)
			result += " " + expense.toString() + "\n";
		result += "\n";
	}

	char *charArray = new char[result.length() + 1];
	strcpy(charArray, result.c_str());
	ofstream ReportDB("dayReportDB.dat", ios::binary);
	ReportDB.write(charArray, report.size() * sizeof(report));
	ReportDB.close();
}

void Report::addToFileWeekReport(ReportGenerator rp, Date date, vector<Account *> &accounts)
{
	report = rp.generateWeekReport(date, accounts);
	string result;
	for (auto &pair : report)
	{
		result += pair.first.toString() + ":\n";
		for (auto &expense : pair.second)
			result += " " + expense.toString() + "\n";
		result += "\n";
	}

	char *charArray = new char[result.length() + 1];
	strcpy(charArray, result.c_str());
	ofstream ReportDB("weekReportDB.dat", ios::binary);
	ReportDB.write(charArray, report.size() * sizeof(report));
	ReportDB.close();
}

void Report::addToFileMonthReport(ReportGenerator rp, Date date, vector<Account *> &accounts)
{
	report = rp.generateMonthReport(date, accounts);
	string result;
	for (auto &pair : report)
	{
		result += pair.first.toString() + ":\n";
		for (auto &expense : pair.second)
			result += " " + expense.toString() + "\n";
		result += "\n";
	}

	char *charArray = new char[result.length() + 1];
	strcpy(charArray, result.c_str());
	ofstream ReportDB("monthReportDB.dat", ios::binary);
	ReportDB.write(charArray, report.size() * sizeof(report));
	ReportDB.close();
}

void Report::showWeekRatingByPrice(ReportGenerator rp, Date date, vector<Account *> &accounts)
{
	report = rp.generateWeekReport(date, accounts);
	int count = 0;
	for (auto el : report)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << "Day report: "
				 << "\n";
			cout << "Date: " << el.first << "\n";
			cout << "Info: "
				 << "\n";
			cout << el.second[i] << "\n";
			;
		}
	}
}

void Report::showMonthRatingByPrice(ReportGenerator rp, Date date, vector<Account *> &accounts)
{
	report = rp.generateWeekReport(date, accounts);
	int count = 0;
	for (auto el : report)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << "Day report: "
				 << "\n";
			cout << "Date: " << el.first << "\n";
			cout << "Info: "
				 << "\n";
			cout << el.second[i] << "\n";
			;
		}
	}
}

void Report::showWeekRatingByCategory(ReportGenerator rp, Date date, vector<Account *> &accounts)
{
	vector<Category> categoryVect;
	vector<int> categoryVectCount;
	report = rp.generateWeekReport(date, accounts);
	for (auto el : report)
	{
		for (auto elem : el.second)
		{
			Category tmp = elem.getCategory();
			for (int i = 0; i < categoryVect.size(); i++)
				if (categoryVect[i] != tmp)
					categoryVect.push_back(tmp);
		}
	}

	for (int i = 0; i < categoryVect.size(); i++)
	{
		int count = 0;
		Category tmp = categoryVect[i];
		for (auto el : report)
		{
			for (auto elem : el.second)
			{
				Category tmp = elem.getCategory();
				for (int i = 0; i < categoryVect.size(); i++)
					if (categoryVect[i] == tmp)
						count++;
			}
		}

		categoryVectCount.push_back(count);
	}

	multimap<int, Category> CategoryMap;
	for (int i = 0; i < categoryVect.size(); i++)
		CategoryMap.insert({categoryVectCount[i], categoryVect[i]});
	int num = 1;
	cout << "Week rating by category: "
		 << "\n";
	;
	for (auto el : CategoryMap)
	{
		cout << " " << num << ". " << el.second << " (" << el.first << " expenses)"
			 << "\n";
		;
		num++;
		if (num == 3)
			break;
	}
}

void Report::showMonthRatingByCategory(ReportGenerator rp, Date date, vector<Account *> &accounts)
{
	vector<Category> categoryVect;
	vector<int> categoryVectCount;
	report = rp.generateMonthReport(date, accounts);
	for (auto el : report)
	{
		for (auto elem : el.second)
		{
			Category tmp = elem.getCategory();
			for (int i = 0; i < categoryVect.size(); i++)
				if (categoryVect[i] != tmp)
					categoryVect.push_back(tmp);
		}
	}

	for (int i = 0; i < categoryVect.size(); i++)
	{
		int count = 0;
		Category tmp = categoryVect[i];
		for (auto el : report)
		{
			for (auto elem : el.second)
			{
				Category tmp = elem.getCategory();
				for (int i = 0; i < categoryVect.size(); i++)
					if (categoryVect[i] == tmp)
						count++;
			}
		}

		categoryVectCount.push_back(count);
	}

	multimap<int, Category> CategoryMap;
	for (int i = 0; i < categoryVect.size(); i++)
		CategoryMap.insert({categoryVectCount[i], categoryVect[i]});
	int num = 1;
	cout << "Week rating by category: "
		 << "\n";
	;
	for (auto el : CategoryMap)
	{
		cout << " " << num << ". " << el.second << " (" << el.first << " expenses)"
			 << "\n";
		;
		num++;
		if (num == 3)
			break;
	}
}

void Report::addToFileWeekRatingByPrice(ReportGenerator rp, Date date, vector<Account *> &accounts)
{
	report = rp.generateWeekReport(date, accounts);
	string result;
	for (auto el : report)
	{
		result += el.first.toString() + ":\n";
		for (int i = 0; i < 3; i++)
			result += " " + el.second[i].toString() + "\n";
		result += "\n";
	}

	char *charArray = new char[result.length() + 1];
	strcpy(charArray, result.c_str());
	ofstream RatingDB("weekRatingDB.dat", ios::binary);
	RatingDB.write(charArray, report.size() * sizeof(report));
	RatingDB.close();
}

void Report::addToFileMonthRatingByPrice(ReportGenerator rp, Date date, vector<Account *> &accounts)
{
	report = rp.generateMonthReport(date, accounts);
	string result;
	for (auto el : report)
	{
		result += el.first.toString() + ":\n";
		for (int i = 0; i < 3; i++)
			result += " " + el.second[i].toString() + "\n";
		result += "\n";
	}

	char *charArray = new char[result.length() + 1];
	strcpy(charArray, result.c_str());
	ofstream RatingDB("monthRatingDB.dat", ios::binary);
	RatingDB.write(charArray, report.size() * sizeof(report));
	RatingDB.close();
}

void Report::addToFileWeekRatingByCategory(ReportGenerator rp, Date date, vector<Account *> &accounts)
{
	vector<Category> categoryVect;
	vector<int> categoryVectCount;
	report = rp.generateWeekReport(date, accounts);
	for (auto el : report)
	{
		for (auto elem : el.second)
		{
			Category tmp = elem.getCategory();
			for (int i = 0; i < categoryVect.size(); i++)
				if (categoryVect[i] != tmp)
					categoryVect.push_back(tmp);
		}
	}

	for (int i = 0; i < categoryVect.size(); i++)
	{
		int count = 0;
		Category tmp = categoryVect[i];
		for (auto el : report)
		{
			for (auto elem : el.second)
			{
				Category tmp = elem.getCategory();
				for (int i = 0; i < categoryVect.size(); i++)
					if (categoryVect[i] == tmp)
						count++;
			}
		}

		categoryVectCount.push_back(count);
	}

	multimap<int, Category> CategoryMap;
	for (int i = 0; i < categoryVect.size(); i++)
		CategoryMap.insert({categoryVectCount[i], categoryVect[i]});

	string result;
	for (auto el : CategoryMap)
	{
		result += to_string(el.first) + ":\n";
		for (int i = 0; i < 3; i++)
			result += " " + el.second.toString() + "\n";
		result += "\n";
	}

	char *charArray = new char[result.length() + 1];
	strcpy(charArray, result.c_str());
	ofstream RatingDB("weekRatingByCategoryDB.dat", ios::binary);
	RatingDB.write(charArray, report.size() * sizeof(report));
	RatingDB.close();
}

void Report::addToFileMonthRatingByCategory(ReportGenerator rp, Date date, vector<Account *> &accounts)
{
	vector<Category> categoryVect;
	vector<int> categoryVectCount;
	report = rp.generateMonthReport(date, accounts);
	for (auto el : report)
	{
		for (auto elem : el.second)
		{
			Category tmp = elem.getCategory();
			for (int i = 0; i < categoryVect.size(); i++)
				if (categoryVect[i] != tmp)
					categoryVect.push_back(tmp);
		}
	}

	for (int i = 0; i < categoryVect.size(); i++)
	{
		int count = 0;
		Category tmp = categoryVect[i];
		for (auto el : report)
		{
			for (auto elem : el.second)
			{
				Category tmp = elem.getCategory();
				for (int i = 0; i < categoryVect.size(); i++)
					if (categoryVect[i] == tmp)
						count++;
			}
		}

		categoryVectCount.push_back(count);
	}

	multimap<int, Category> CategoryMap;
	for (int i = 0; i < categoryVect.size(); i++)
		CategoryMap.insert({categoryVectCount[i], categoryVect[i]});

	string result;
	for (auto el : CategoryMap)
	{
		result += to_string(el.first) + ":\n";
		for (int i = 0; i < 3; i++)
			result += " " + el.second.toString() + "\n";
		result += "\n";
	}

	char *charArray = new char[result.length() + 1];
	strcpy(charArray, result.c_str());
	ofstream RatingDB("monthRatingByCategoryDB.dat", ios::binary);
	RatingDB.write(charArray, report.size() * sizeof(report));
	RatingDB.close();
}