#include <iostream>
#include <map>
#include "Student.h"
using namespace std;

int main() {
	map<string, float> students;
	for (int i = 0; i < 5; i++) 
    {
		string tmp1;
		float tmp2;
		cout << "Enter name: ";
		cin >> tmp1;
		cout << "Enter average mark: ";
		cin >> tmp2;
		students.insert(make_pair(tmp1, tmp2));
	}
	for (const auto& elem : students) cout << "Name: " << elem.first << "\n" << "Average mark: " << elem.second << "\n";

	map<Student, float> students2;
	for (int i = 0; i < 5; i++) {
		Student tmp1;
		float tmp2;
		cin >> tmp1;
		cout << "Enter average mark: ";
		cin >> tmp2;
		students2.insert(make_pair(tmp1, tmp2));
	}
	for (const auto& elem : students2) cout << elem.first << "\n" << "Average mark: " << elem.second << "\n";

	string searchName;
	int searchAge;
	cout << "Enter name to search: ";
	cin >> searchName;
	cout << "Enter age to search: ";
	cin >> searchAge;
	auto searchResult = students2.find(Student(searchName, searchAge));
	if (searchResult != students2.end()) 
    {
        cout << "Student found! " << "\n";
    }
	else 
    {
        cout << "Student not found! " << "\n";
    }
}