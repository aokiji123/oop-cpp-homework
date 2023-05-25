#include <iostream>
#include <set>
#include "Point.h"
using namespace std;

int main()
{
	srand(time(0));

	set<Point<double> > set1;

	for (int i = 0; i < 5; i++)
	{
		set1.insert(
			Point<double>(
				rand() % 10,
				rand() % 10,
				rand() % 10
			)
		);
	}

	set<Point<double> >::const_iterator it;
	it = set1.begin();

	while (it != set1.end())
	{
		cout << *it << ", ";
		it++;
	}
	cout << "\n";

	cout << "\nSearch for Point: ";

	Point<double> toSearch;

	cin >> toSearch;

	it = set1.find(toSearch);

	if (it != set1.end())
		cout << "Found!\n\n";
	else
		cout << "Not found!\n\n";

	set<set<Point<int> > > set2;

	for (int i = 0; i < 3; i++)
	{
		set<Point<int> > tmp;

		for (int j = 0; j < 5; j++)
		{
			tmp.insert(
				Point<int>(
					rand() % 100,
					rand() % 100,
					rand() % 100
				)
			);
		}
		set2.insert(tmp);
	}

	set<set<Point<int> > >::const_iterator it1;
	it1 = set2.begin();

	while (it1 != set2.end())
	{
		set<Point<int> >::const_iterator it2;
		it2 = (*it1).begin();

		while (it2 != (*it1).end())
		{
			cout << *it2 << ", ";
			it2++;
		}
		cout << "\n";
		it1++;
	}
	cout << "\n";

	cout << "\nSearch for Point: ";

	Point<int> toSearch2;

	cin >> toSearch2;

	bool isFound = false;

	it1 = set2.begin();

	while (it1 != set2.end())
	{
		set<Point<int> >::const_iterator it2;
		it2 = (*it1).find(toSearch2);

		if (it2 != (*it1).end())
			isFound = true;

		it1++;
	}

	if (isFound)
	{
		cout << "Found!\n";
	}
	else
	{
		cout << "Not found!\n";
	}

	set<set<set<Point<int> > > > set3;

	for (int i = 0; i < 3; i++)
	{
		set<set<Point<int> > > tmp1;

		for (int j = 0; j < 3; j++)
		{
			set<Point<int> > tmp2;

			for (int k = 0; k < 5; k++)
			{
				tmp2.insert(
					Point<int>(
						rand() % 100,
						rand() % 100,
						rand() % 100
					)
				);
			}
			tmp1.insert(tmp2);
		}
		set3.insert(tmp1);
	}

	set<set<set<Point<int> > > >::const_iterator it2;
	it2 = set3.begin();

	while (it2 != set3.end())
	{
		set<set<Point<int> > >::const_iterator it3;
		it3 = (*it2).begin();

		while (it3 != (*it2).end())
		{
			set<Point<int> >::const_iterator it4;
			it4 = (*it3).begin();

			while (it4 != (*it3).end())
			{
				cout << *it4 << ", ";
				it4++;
			}
			cout << "\n";
			it3++;
		}
		cout << "\n";
		it2++;
	}

	cout << "Search for Point: ";

	Point<int> toSearch3;

	cin >> toSearch3;

	bool isFound2 = false;

	it2 = set3.begin();

	while (it2 != set3.end())
	{
		set<set<Point<int> > >::const_iterator it3;
		it3 = (*it2).begin();

		while (it3 != (*it2).end())
		{
			set<Point<int> >::const_iterator it4;
			it4 = (*it3).find(toSearch3);

			if (it4 != (*it3).end())
				isFound2 = true;

			it3++;
		}
		it2++;
	}

	if (isFound2)
	{
		cout << "Found!\n";
	}
	else {
		cout << "Not found!\n";
	}
}
