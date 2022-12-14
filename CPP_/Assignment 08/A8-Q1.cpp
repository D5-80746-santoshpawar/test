#include <iostream>

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

Emenu menu()
{
    int choice;
    cout << "Enter operation code to perform:" << endl;
    cout << "0:Exit" << endl;
    cout << "1:Enter Manger Data" << endl;
    cout << "2:Enter Salesman Data" << endl;
    cout << "3:Enter SalesManger Data" << endl;
    cout << "4:Display Employees" << endl;
    cout << "5:Display Mangers" << endl;
    cout << "6:Display Salesman" << endl;
    cout << "7:Display SalesMangers" << endl;

    cin >> choice;
    return Emenu(choice);
}

int main()
{
    int choice;
    float value;
    int res;
    int index = 0;
    int MCount = 0;
    int SCount = 0;
    int SMCount = 0;
    Employee *ptr[10];

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case ACC_MAN:
            if (index < 10)
            {
                ptr[index] = new Manger(); // upcasting
                ptr[index]->accept();
                index++;
            }
            else
                cout << "Employee limit Reached !" << endl;
            break;

        case ACC_SALE:
            if (index < 10)
            {
                ptr[index] = new Salesman(); // upcasting
                ptr[index]->accept();
                index++;
                SCount++;
            }
            else
                cout << "Employee limit Reached !" << endl;
            break;

        case ACC_SLMN:
            if (index < 10)
            {
                ptr[index] = new SalesManager(); // upcasting
                ptr[index]->accept();
                index++;
                SMCount++;
            }
            else
                cout << "Employee limit Reached !" << endl;
            break;

        case PRINT_ALL:
            if (ptr != NULL)
            {
                for (int i = 0; i < index; i++)
                    ptr[i]->display();
            }
            break;

        case PRINT_MANAGERS:
            cout << "Following are the Manger Employees:" << endl;
            for (int i = 0; i < index; i++)
            {
                cout << "inside Manger for" << endl;

                if (typeid(ptr[i]) == typeid(Manger))
                {
                    cout << "inside Manger" << endl;
                    Manger *mtr = dynamic_cast<Manger *>(ptr[i]);
                    if (mtr != NULL)
                        mtr->display();
                    MCount++;
                }
            }
            cout << "Total Manager Employee count:" << MCount << endl;

            break;

        case PRINT_SALESMAN:
            cout << "Following are the Salesman Employees:" << endl;
            for (int i = 0; i < index; i++)
            {
                if (typeid(ptr[i]) == typeid(Salesman))
                {
                    Salesman *str = dynamic_cast<Salesman *>(ptr[i]);
                    if (str != NULL)
                        str->display();
                }
            }
            cout << "Total Salesman Employee count:" << SCount << endl;
            break;

        case PRINT_SMANAGER:
            cout << "Following are the Manger Employees:" << endl;
            for (int i = 0; i < index; i++)
            {
                cout << typeid(ptr[i]).name() << endl;
                if (typeid(*ptr[i]) == typeid(SalesManager))
                {
                    SalesManager *smtr = dynamic_cast<SalesManager *>(ptr[i]);
                    if (smtr != NULL)
                        smtr->display();
                }
            }
            cout << "Total SalesManager Employee count:" << SMCount << endl;
            break;

        default:
            cout << "invlid selection" << endl;
            break;
        }
    }

    if (ptr != NULL)
    {
        for (int i = 0; i < index; i++)
            delete ptr[i];
        // delete[]ptr;
    }
    cout << "Thank you for using the program !" << endl;
    return 0;
}
