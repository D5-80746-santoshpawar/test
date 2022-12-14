#include <iostream>
using namespace std;
class Distance
{
private:
    int feets;
    int inches;

public:
    Distance()
    {
        this->feets = 1;
        this->inches = 1;
    }
    Distance(int feet, int inch)
    {
        this->feets = feet;
        this->inches = inch;
    }
    void displayDistance()
    {
        cout << " Feet :" << this->feets << endl;
        cout << " Inches :" << this->inches << endl;
    }
    void acceptDistance()
    {
        cout << " Enter Feet :" << endl;
        cin >> this->feets;
        cout << " Enter Inches :" << endl;
        cin >> this->inches;
    }
    Distance operator+(Distance other)
    {
        Distance d1;
        d1.feets = this->feets + other.feets;
        d1.inches = this->inches + other.inches;
        return d1;
    }
    Distance operator++()
    {
        inches++;
        if (inches >= 10)
        {
            feets++;
            inches -= 10;
        }
        return *this;
    }
    friend bool operator==(Distance &d1, Distance &d2)
    {
        return (d1.feets == d2.feets && d1.inches == d2.inches);
    }
    friend std::ostream &operator<<(ostream &out, Distance d)
    {
        out << d.feets << "feets" << d.inches << "Inches";
        return out;
    }
    friend std::istream &operator>>(istream &in, Distance d)
    {
        cout << "Enter feets" << endl;
        in >> d.feets;
        cout << "Enter inches" << endl;
        in >> d.inches;
        return in;
    }
    friend Distance operator--(Distance &d, int)
    {
        Distance temp(d);
        d.inches-- if (d.inches < 0)
        {
            d.feet--;
            d.inches += 10;
        }
    }
};
int main()
{

    Distance d2, d3;
    Distance d4 = (d2 + d3);
    d2.acceptDistance();
    d2.displayDistance();
    d3.acceptDistance();
    d3.displayDistance();
    d4.displayDistance();
    d2++;
    d2.displayDistance();
    d3--;
    d3.displayDistance();
    if (d2 == d3)
    {
        cout << "Equals" << endl;
    }
    else
        cout << "Not Equal" << endl;
    return 0;
}