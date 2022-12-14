#include <iostream>
using namespace std;
class Toolbooth
{
private:
    int total_cars;
    double total_money;
    int paid_car;
    int unpaid_car;

public:
    Toolbooth()
    {
        this->total_cars = 0;
        this->total_money = 0;
        this->paid_car = 0;
        this->unpaid_car = 0;
    }
    void PayingCar()
    {
        this->paid_car++;
        this->total_cars++;
        this->total_money += 0.50;
    }
    void NopayingCar()
    {
        this->unpaid_car++;
        this->total_cars++;
    }
    void PrintonConsole()
    {
        cout << "******" << endl;
        cout << "tax collection:" << this->total_money << "Rs" << endl;
        cout << "Paying cars:" << this->paid_car << endl;
        cout << "Non paying cars:" << this->unpaid_car << endl;
        cout << "******" << endl;
    }
    void PrintDefault()
    {
        Toolbooth booth;
        paid_car = 1;
        total_cars = 2;
        total_money = 1;
        unpaid_car = 2;
        booth.PrintonConsole();
    }
};
int main()
{
    Toolbooth t1;
    while (true)
    {

        int choice;
        cout << "***Menu***" << endl;
        cout << "0.Exit" << endl;
        cout << "1.Paying Car" << endl;
        cout << "2.Nopaying car" << endl;
        cout << "3.Get status of Paying & Nonpaying Cars" << endl;
        cout << "4.Set Default data" << endl;
        cout << "Enter the choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "You are Exiting" << endl;
            break;
        case 1:
            t1.PayingCar();
            break;
        case 2:
            t1.NopayingCar();
            break;
        case 3:
            t1.PrintonConsole();
            break;
        case 4:
            t1.PrintDefault();
            break;

        default:
            cout << "You enter invalid choice" << endl;
            break;
        }
    }

    return 0;
}
