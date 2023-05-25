#include <iostream>
using namespace std;

class Student {
private:
	string name;
	int age;

public:
	Student() : name("No name"), age(0) {}
	Student(string name, int age) : name(name), age(age) {}

	bool operator < (const Student& student) const { 
        return age < student.age; 
    };

	friend istream& operator >> (istream& i, Student& student) {
		cout << "Enter name: ";
		i >> student.name;
		cout << "Enter age: ";
		i >> student.age;
		return i;
	}

	friend ostream& operator << (ostream& o, const Student& student) {
		o << "Name: " << student.name << "\n" << "Age: " << student.age;
		return o;
	}
};