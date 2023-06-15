#include <iostream>
#include <string>
using namespace std;

class Pump {
public:
    void FillPump()
    {
        cout << "Fill pump" << "\n";
    }

    void EmptyPump()
    {
        cout << "Empty pump" << "\n";
    }
};

class Heater {
public:
    void HeatWater()
    {
        cout << "Water heating" << "\n";
    }

    void CoolWater()
    {
        cout << "Water cooling" << "\n";
    }
};

class Motor {
public:
    void StartMotor()
    {
        cout << "Turning motor on" << "\n";
    }

    void StopMotor()
    {
        cout << "Turning motor off" << "\n";
    }
};

class RinseAid {
public:
    void StartRinse()
    {
        cout << "Starting rinse" << "\n";
    }

    void StopRinse()
    {
        cout << "Stopping rinse" << "\n";
    }
};

class WashingMachine {
private:
    Pump pump;
    Heater heater;
    Motor motor;
    RinseAid rinseaid;

public:
    WashingMachine(Pump pump, Motor motor, Heater heater, RinseAid rinseaid): pump(pump), motor(motor), heater(heater), rinseaid(rinseaid) {}

    void StartWashing()
    {
        pump.FillPump();
        heater.HeatWater();
        motor.StartMotor();
        rinseaid.StartRinse();
    }

    void StopWashing()
    {
        rinseaid.StopRinse();
        motor.StopMotor();
        heater.CoolWater();
        pump.EmptyPump();
    }
};

class User {
public:
    void Washing(WashingMachine& washingMachine)
    {
        cout << "Starting washing" << "\n";
        washingMachine.StartWashing();
        cout << "\n\n";
        cout << "Stopping washing" << "\n";
        washingMachine.StopWashing();
    }
};

int main()
{
    Pump pump;
    Motor motor;
    Heater heater;
    RinseAid rinser;

    WashingMachine washingMachine(pump, motor, heater, rinser);

    User user;
    user.Washing(washingMachine);
}