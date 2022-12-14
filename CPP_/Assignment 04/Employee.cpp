#include <iostream>
using namespace std;
class Employee
{
public:
    int empid;
    float empsalary;

public:
    Employee()
    {
        this->empid = 0;
        this->empsalary = 0.0;
    }
    Employee(int id, float salary)
    {
        this->empid = id;
        this->empsalary = salary;
    }
    int getEmpid()
    {
        return this->empid;
    }
    void setEmpid(int id)
    {
        this->empid = id;
    }
    float getEmsalary()
    {
        return this->empsalary;
    }
    void setEmpsalary(float salary)
    {
        this->empsalary = salary;
    }
    void AcceptRecord()
    {
        cout << "Enter Employee Id: " << endl;
        cin >> this->empid;
        cout << "Enter Employee Salary: " << endl;
        cin >> this->empsalary;
    }
    void DisplayRecord()
    {
        cout << "Employee Id: " << this->empid << endl;
        cout << "Employee Salary: " << this->empsalary << endl;
    }
};
class Manager : virtual public Employee
{
private:
    float empbonus;

public:
    Manager()
    {
        this->empbonus = 0.0;
    }
    Manager(float bonus, int id, float salary):Employee(id,salary)
    {
        this->empbonus = bonus;
    }
    float getEmpbonus()
    {
        return this->empbonus;
    }
    void setEmpbonus(float bonus)
    {
        this->empbonus = bonus;
    }
    void AcceptManager()
    {
        cout << "Enter Bonus" << endl;
        cin >> this->empbonus;
        Employee::AcceptRecord();
    }
    void DisplayManager()
    {
        Employee::DisplayRecord();
        cout << " Bonus:" << this->empbonus << endl;
    }
};
class Salesman :virtual public Employee
{
protected:
    float commission;

public:
    Salesman()
    {
        this->commission = 0;
    }
    Salesman(float comm,int id,float salary):Employee(id,salary)
    {
        this->commission = comm;
    }
    float getCommission()
    {
        return this->commission;
    }
    void setCommission(float comm)
    {
        this->commission = comm;
    }
    void AcceptSalesman()
    {
        cout << "Enter commission" << endl;
        cin >> this->commission;
        Employee::AcceptRecord();
    }
    void DisplaySalesman()
    {
        Employee::DisplayRecord();
        cout << "Commission :" << this->commission << endl;
    }
};
class Sales_Manager : public Salesman, public Manager
{
public:
    Sales_Manager()
    {
    }
    Sales_Manager(int id, float salary, float bonus, float comm):Employee(id,salary),Salesman(id,salary,comm),Manager(id,salary,bonus)
    {
    }
    void Accept()
    {
        float value;
        cout << " Enter Sales Manager  Details" << endl;
        Manager::AcceptManager();
        cout << " Enter Commission : " << endl;
        cin>>value;
      Salesman::setCommission(value);
    }
    void display()
    {
        cout << "Sales Manager  Details" << endl;
        Manager::DisplayManager();
        cout << "Commission : " << Sales_Manager::Salesman::getCommission() << endl;
    }
};
int main()
{
    Employee e1;
    e1.AcceptRecord();
    cout << "******Employee Details****** " << endl;
    e1.DisplayRecord();
    cout << endl;
    Manager m1;
    m1.AcceptManager();
    cout << "******Manager Details****** " << endl;
    m1.DisplayManager();
    cout << endl;
    Salesman s1;
    s1.AcceptSalesman();
    cout << "******Salesman Details****** " << endl;
    s1.DisplaySalesman();
    cout << endl;
    Sales_Manager Sm1;
    Sm1.Accept();
    cout << "******Sales Manager Details****** " << endl;
    Sm1.display();

    return 0;
}
