#include <iostream>
using namespace std;
namespace YLeap
{
    class Leap
    {
    private:
        int day;
        int month;
        int year;

    public:
        void initLeap()
        {
            this->day = 0;
            this->month = 0;
            this->year = 0000;
        }
        void acceptDate()
        {
            cout << "Enter Date " << endl;
            cout << "Day : " << endl;
            cin >> day;
            cout << "Month " << endl;
            cin >> month;
            cout << "Year" << endl;
            cin >> year;
        }
        void printDate()
        {
            cout << " EnteredDate :" << day << "/" << month << "/" << year << endl;
        }
        bool isLeapyear()
        {
            return ((this->year%400)==0);
        }
    };
}
using namespace YLeap;
int main()
{

    while ((true))
    {
        Leap l1;
        int choice;
        cout << "0.Exit" << endl;
        cout << "1.AcceptRecord" << endl;
        cout << "2.PrintRecord" << endl;
        cout << "3.PrintDefined" << endl;
        cout << "4.Check its leap or not" << endl;
        cout << "Enter the choice " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            l1.acceptDate();
            break;
        case 2:
            l1.printDate();
            break;
        case 3:
            l1.initLeap();
            break;
        case 4:
           /*int year;
            cout << "Enter the year :";
            cin >> year; */
            if ((l1.isLeapyear()))
            {
                cout << "Its is Leap Year" << endl;
            }
            else
            {
                cout << "Its is Not Leap Year" << endl;
            }
            break;
        default:
            cout << "You enter wrong choice" << endl;
            break;
        }
    }
    return 0;
}
