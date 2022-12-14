#include <iostream>
using namespace std;
namespace TDate
{
    class Date
    {
    private:
        int day;
        int month;
        int year;

    public:
        void initDate()
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
            cout << " Entered Date :" << day << "/" << month << "/" << year << endl;
        }
    };
}
using namespace TDate;
int main()
{

    while ((true))
    {
        Date d1;
        int choice;
        cout << "0.Exit" << endl;
        cout << "1.AcceptRecord" << endl;
        cout << "2.PrintRecord" << endl;
        cout << "3.PrintDefined Or intialized " << endl;
        cout << "Enter the choice " << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << " You are Exit" << endl;
            return 0;
        case 1:
            d1.acceptDate();
            break;
        case 2:
            d1.printDate();
            break;
        case 3:
            d1.initDate();
            break;

        default:
            cout
                << "You enter invalid choice" << endl;
            break;
        }
    }
    return 0;
}
