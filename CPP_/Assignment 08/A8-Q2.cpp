#include <iostream>
#include <vector>

using namespace std;

class Employee
{
private:
    int id;
    float sal;

public:
    Employee()
    {
        this->id = 00;
        this->sal = 1000.00f;
    }

    Employee(int id, float sal)
    {
        this->id = id;
        this->sal = sal;
    }

    int getId()
    {
        return this->id;
    }

    void setId(int id)
    {
        this->id = id;
    }

    float getSal()
    {
        return this->sal;
    }

    void setSal(float sal)
    {
        this->sal = (float)sal;
    }

    virtual void display()
    {
        cout << "Emp Id:" << this->id << endl;
        ;
        cout << "Emp Salary:" << this->sal << endl;
    }

    virtual void accept()
    {
        cout << "Enter the Employee Id:" << endl;
        cin >> this->id;
        cout << "Enter the Employee salary: " << endl;
        cin >> this->sal;
    }
};

class Manger : virtual public Employee
{
private:
    float bonus;

protected:
    void acceptManger()
    {

        cout << "Enter bonus for the Manger Position" << endl;
        cin >> this->bonus;
    }

    void displayManger()
    {
        cout << "Bonus for Manger Position:" << this->bonus << endl;
    }

public:
    Manger()
    {
        this->bonus = 0;
    }

    Manger(int id, float sal, float bonus)
    {

        this->bonus = bonus;
    }

    float getbonus()
    {
        return this->bonus;
    }

    void setbonus(float bonus)
    {
        this->bonus = bonus;
    }

    void display()
    {
        Employee::display();
        this->displayManger();
    }

    void accept()
    {
        Employee::accept();
        this->acceptManger();
    }
};

class Salesman : virtual public Employee
{
private:
    float comm;

protected:
    void acceptSalesman()
    {

        cout << "Enter commission for the Sales Dept Employee" << endl;
        cin >> this->comm;
    }

    void displaySalesman()
    {
        cout << "Commision for Sales Dept Employee:" << this->comm << endl;
    }

public:
    Salesman()
    {
        this->comm = 0;
    }

    Salesman(int id, float sal, float comm)
    {
        this->comm = comm;
    }

    float getcomm()
    {
        return this->comm;
    }

    void setcomm(float comm)
    {
        this->comm = comm;
    }

    void display()
    {
        Employee::display();
        this->displaySalesman();
    }

    void accept()
    {
        Employee::accept();
        this->acceptSalesman();
    }
};

class SalesManager : public Manger, public Salesman
{
public:
    SalesManager()
    {
        int id = 0;
        float sal = 0;
        float bonus = 0;
        float comm = 0;
    }

    SalesManager(int id, float sal, float bonus, float comm);

    void display()
    {
        Employee::display();
        this->displayManger();
        this->displaySalesman();
    }

    void accept()
    {
        Employee::accept();
        this->acceptManger();
        this->acceptSalesman();
    }
};

enum Emenu
{
    EXIT,
    ACC_MAN,
    ACC_SALE,
    ACC_SLMN,
    PRINT_ALL,
    PRINT_MANAGERS,
    PRINT_SALESMAN,
    PRINT_SMANAGER,
};
void ShowAllEmployees(vector<Employee *> &eptr)
{
    int mcount = 0;
    int s1count = 0;
    int smcount = 0;
    for (int i = 0; i < eptr.size(); i++)
    {
        if (typeid(*eptr.at(i)) == (typeid(Manger)))
        {
            mcount++;
        }
        else if (typeid(*eptr.at(i)) == (typeid(Salesman)))
        {
            s1count++;
        }
        else if (typeid(*eptr.at(i)) == (typeid(SalesManager)))
        {
            smcount++;
        }
    }
    cout << "No.of Managers: " << mcount << endl;
    cout << "No.of Salesman: " << s1count << endl;
    cout << "No.of Salesman Manager: " << smcount << endl;
}
void ShowAllManager(vector<Employee *> &eptr)
{
    for (int i = 0; i < eptr.size(); i++)
    {
        if (typeid(*eptr.at(i)) == (typeid(SalesManager)))
        {
            eptr.at(i)->display();
        }
    }
}
void ShowAllSalesMan(vector<Employee *> &eptr)
{
    for (int i = 0; i < eptr.size(); i++)
    {
        if (typeid(*eptr.at(i)) == (typeid(Salesman)))
        {
            eptr.at(i)->display();
        }
    }
}
void ShowAllManager(vector<Employee *> &eptr)
{
    for (int i = 0; i < eptr.size(); i++)
    {
        if (typeid(*eptr.at(i)) == (typeid(SalesManager)))
        {
            eptr.at(i)->display();
        }
    }
}
Emenu menu()
{
    int choice;
    cout << "Enter operation code to perform:" << endl;
    cout << "0:Exit" << endl;
    cout << "1:Enter Manger Data" << endl;
    cout << "2:Enter Salesman Data" << endl;
    cout << "3:Enter SalesManger Data" << endl;
    cout << "4:Display All Employees" << endl;
    cout << "5:Display All Mangers" << endl;
    cout << "6:Display All Salesman" << endl;
    cout << "7:Display All SalesMangers" << endl;

    cin >> choice;
    return Emenu(choice);
}

int main()
{

    vector<Employee *> Employee;
    Employee *eptr = NULL;
    int choice;
    float value;
    int res;
    int index = 0;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case ACC_MAN:

            eptr = new Manger();
            eptr->acceptDetails();
            Employee.push_back(eptr);
            index++;
            break;

        case ACC_SALE:
            eptr = new Salesman();
            eptr->acceptDetails();
            Employee.push_back(eptr);
            index++;
            break;

        case ACC_SLMN:
            eptr = new SalesManager();
            eptr->acceptDetails();
            Employee.push_back(eptr);
            index++;
            break;
        case PRINT_ALL:
            ShowAllEmployees(Employee);
            break;

        case PRINT_MANAGERS:
            ShowAllManager(Employee);
            break;
        case PRINT_SALESMAN:
            ShowAllSalesMan(Employee);
            break;
        case PRINT_SMANAGER:
            ShowAllManager(Employee);
        default:
            cout << "invlid selection" << endl;
            break;
        }
    }
    delete eptr;
    cout << "Thank you for using the program !" << endl;
    return 0;
}
