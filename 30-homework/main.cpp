#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class LengthComparator {
public:
    bool operator()(const string& str1, const string& str2) {
        return str1.length() < str2.length();
    }
};

class Multiplier {
private:
    int coefficient;

public:
    Multiplier(int coeff) : coefficient(coeff) {}

    void operator()(int& num) {
        num *= coefficient;
    }
};

class Incrementer {
private:
    int constant;

public:
    Incrementer(int value) : constant(value) {}

    void operator()(int& num) {
        num += constant;
    }
};

int main() {
    vector<string> strings = { "apple", "banana", "cherry", "date" };
    sort(strings.begin(), strings.end(), LengthComparator());

    cout << "Sorted strings: ";
    for (const string& str : strings) {
        cout << str << " ";
    }
    cout << "\n";

    vector<int> numbers = { 1, 2, 3, 4, 5 };
    int multiplier = 3;

    cout << "Original numbers: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << "\n";

    for_each(numbers.begin(), numbers.end(), Multiplier(multiplier));

    cout << "Multiplied numbers: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << "\n";

    vector<int> values = { 10, 20, 30, 40, 50 };
    int increment = 5;

    cout << "Original values: ";
    for (int value : values) {
        cout << value << " ";
    }
    cout << "\n";

    for_each(values.begin(), values.end(), Incrementer(increment));

    cout << "Incremented values: ";
    for (int value : values) {
        cout << value << " ";
    }
    cout << "\n";
}
