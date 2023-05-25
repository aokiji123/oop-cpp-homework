#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compareStrings(const string& str1, const string& str2) {
    return str1.length() < str2.length();
}

int main() {
    vector<string> strings;
    strings.push_back("aaa");
    strings.push_back("bb");
    strings.push_back("c");
    strings.push_back("dddd");
    strings.push_back("eeeee");

    sort(strings.begin(), strings.end(), compareStrings);

    for (const auto& str : strings) {
        cout << str << " ";
    }
    
    return 0;
}
