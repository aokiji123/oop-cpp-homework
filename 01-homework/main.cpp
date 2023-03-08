#include <iostream>
using namespace std;

class Fraction
{
private:
  int numerator;   // числитель
  int denominator; // знаменатель

public:
  void Input()
  {

    cout << "Enter a numerator: ";
    cin >> numerator;
    cout << "Enter a denominator: ";
    cin >> denominator;
  }

  void OutPut()
  {
    cout << "Numerator: " << numerator << "\n";
    cout << "Denominator: " << denominator << "\n";
  }

  void Plus(int number)
  {
    cout << number << " " << numerator << "/" << denominator << "\n";
  }

  void Minus(int number)
  {
    cout << numerator - (number * denominator) << "/" << denominator << "\n";
  }

  void Multiple(int number)
  {
    cout << numerator * number << "/" << denominator << "\n";
  }

  void Division(int number)
  {
    int newDenominator = denominator * number;
    bool checking = true;

    for (int i = numerator; i != 0; i--)
    {
      if (numerator % i == 0 && newDenominator % i == 0)
      {
        cout << numerator / i << "/" << newDenominator / i << "\n";
        checking = false;
        break;
      }
    }

    if (checking)
      cout << numerator << "/" << newDenominator << "\n";
  }
};

int main()
{
  Fraction fraction;

  fraction.Input();
  cout << "\n";

  fraction.Plus(12);
  cout << "\n";

  fraction.Minus(2);
  cout << "\n";

  fraction.Multiple(6);
  cout << "\n";

  fraction.Division(3);
}