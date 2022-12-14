#include <iostream>
#include <string.h>
using namespace std;
class Date
{
private:
    int day, month, year;

public:
    Date()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    int getDay()
    {
        return this->day;
    }
    int getMonth()
    {
        return this->month;
    }
    int getyear()
    {
        return this->day;
    }
    void setDay(int day)
    {
        this->day = day;
    }
    void setMonth(int month)
    {
        this->month = month;
    }
    void setYear(int year)
    {
        this->year = year;
    }
    void AcceptDate()
    {
        cout << "Enter Day :" << endl;
        cin >> this->day;
        cout << "Enter Month :" << endl;
        cin >> this->month;
        cout << "Enter Year :" << endl;
        cin >> this->year;
    }
    void PrintDate()
    {
        cout << " DD/MM/YY :" << this->day << "/" << this->month << "/" << this->year << endl;
    }
    bool is_leap_year()
    {
        return ((this->year % 400) == 0);
    }
};
class Person:public Date
{
private:
    string name;
    string adress;
    Date birth_date;

public:
    Person()
    {
        this->name = " ";
        this->adress = " ";
    }
    Person(string n1, string adrr, int day, int month, int year)
    {
        this->name = n1;
        this->adress = adrr;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return this->name;
    }
    string getAdress()
    {
        return this->adress;
    }
    void setBirthDate(Date &dob)
    {
        this->birth_date = dob;
    }
    Date getBirthDate()
    {
        return this->birth_date;
    }
    virtual void AcceptData()
    {
        cout << "Enter Name :" << endl;
        cin >> this->name;
        cout << "Enter Adress :" << endl;
        cin >> this->adress;
        cout << " Enter Birth Date" << endl;
        birth_date.AcceptDate();
    }
    virtual void PrintData()
    {
        cout << " Name :" << this->name << endl;
        cout << " Adress :" << this->adress << endl;
        cout << "Birth Date " 
        birth_date.PrintDate();
        cout<< endl;
    }
};
class Employee : public Person
{
private:
    int empid;
    double empsalary;
    string department;
    Date jodate;

public:
    Employee()
    {
        this->empid = 0;
        this->empsalary = 0.0;
        this->department = " ";
    }
    Employee(int id, double salary, string dep)
    {
        this->empid = id;
        this->empsalary = salary;
        this->department = dep;
    }
    void AcceptData()
    {
        Person::AcceptData();
        cout << "Enter Empid" << endl;
        cin >> this->empid;
        cout << "Enter Salaray :" << endl;
        cin >> this->empsalary;
        jodate.AcceptDate();
    }
    void DisplayData()
    {
        Person::PrintData();
        cout << " Empid : " << this->empid << endl;
        cout << "Salaray :" << this->empsalary << endl;
        jodate.PrintDate();
    }
    void setEmpid(int id)
    {
        this->empid = id;
    }
    int getEmpid()
    {
        return this->empid;
    }
    void setEmpSalary(double salary)
    {
        this->empsalary = salary;
    }
    int getEmpSalary()
    {
        return this->empsalary;
    }
    void setJoinDate(Date &jod)
    {
        this->jodate = jod;
    }
    Date getJoinDate()
    {
        return this->jodate;
    }
};
int main()
{
    cout << " *** Checking Date Class ***" << endl;
    Date date;
    date.AcceptDate();
    date.PrintDate();
    cout << endl;
    cout << " This Is Leap Year :" << (date.is_leap_year() ? "Yes" : "No") << endl;

    cout << " *** Checking Person Class ***" << endl;
    Person person;
    person.AcceptData();
    person.PrintData();
    cout << endl;

    cout << " *** Checking Employye Class ***" << endl;
    Employee employee;
    employee.AcceptData();
    employee.PrintData();
    cout << endl;

    return 0;
}