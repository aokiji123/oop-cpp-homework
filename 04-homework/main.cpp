#include "MyString.h"
using namespace std;

int main()
{
  MyString str1("Hello!");
  str1.Print();
  str1.Input();
  cout << str1.MyStrLen() << "\n";

  MyString str2;
  str1.MyStrcpy(str2);
  str2.Print();

  MyString str3("Hi");
  str1.MyStrCat(str3);
  str1.Print();

  str1.MyDelChr('o');
  str1.Print();

  cout << str1.MyStrCmp(str2) << "\n";
}