#include <iostream>
using namespace std;
class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time()
    {
        this->hour = 0;
        this->minute = 0;
        this->second = 0;
    }
    Time(int hour, int minute, int second)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    int getHour()
    {
        return this->hour;
    }
    void setHour(int hour)
    {
        this->hour = hour;
    }
    int getMinute()
    {
        return this->minute;
    }
    void setMinute(int minute)
    {
        this->minute= minute;
    }
    int getSecond()
    {
        return this->second;
    }
    void setSecond(int second)
    {
        this->second = second;
    }
    void printTime()
    {
        cout << this->hour << ":" << this->minute << ":" << this->second << endl;
    }
    bool getindex(int size)
    {
        int index;
        cout << "Enter the Index" << endl;
        cin >>index;
        return  (index < size);
    }
};
int main()
{
    int choice;
    int value, size, index = 0;
    Time *arr;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    arr = new Time[size];
    while (true)
    {
        cout << "1.SetHour" << endl;
        cout << "2.SetMinute" << endl;
        cout << "3.SetSecond" << endl;
        cout << "4.GetHour" << endl;
        cout << "5.GetMinute" << endl;
        cout << "6.GetSecond" << endl;
        cout << "7.Print Time" << endl;
        cout << "8.Exit " << endl;
        cout << "Enter The Choice  " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (arr[index].getindex(size))
                cout << "Enter the Hour" << endl;
            cin >> value;
            if (value > 0 && value <= 12)
                arr[index].setHour(value);
            else
                cout << "Please Enter valid Hour" << endl;
            break;
        case 2:
            if (arr[index].getindex(size))
                cout << "Enter the Minute" << endl;
            cin >> value;
            if (value > 0 && value <= 60)
                arr[index].setMinute(value);
            else
                cout << "Please Enter valid Mintue" << endl;
            break;
        case 3:
            if (arr[index].getindex(size))
                cout << "Enter the Second" << endl;
            cin >> value;
            if (value > 0 && value <= 60)
                arr[index].setSecond(value);
            else
                cout << "Please Enter valid Second" << endl;
            break;
        case 4:
            if (arr[index].getindex(size))
            {
                value = arr[index].getHour();
                cout << "Hour:" << value << endl;
            }
            break;
        case 5:
            if (arr[index].getindex(size))
            {
                value = arr[index].getMinute();
                cout << "Minute:" << value << endl;
            }
            break;
        case 6:
            if (arr[index].getindex(size))
            {
                value = arr[index].getSecond();
                cout << "Second:" << value << endl;
            }
            break;
        case 7:
            for (int i = 0; i < size; i++)

                break;
        case 8:
            cout << "You are Exiting" << endl;
            return 0;
            break;
        default:
            cout << "You are Entered Invalid choice" << endl;
            break;
        }
    }
    cout<<"Thanks For Using Program"<<endl;

    return 0;
}