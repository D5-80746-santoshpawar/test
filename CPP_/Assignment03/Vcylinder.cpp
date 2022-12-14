#include <iostream>
#include <string.h>
using namespace std;
class Vcylinder
{
public:
    double radius;
    double height;
    double result;
    const double pi=3.14;

public:
    Vcylinder()
    {
        this->radius = 0;
        this->height = 0;
    }
     Vcylinder(double radius, double height):pi(3.14)
     {
         this->radius = radius;
         this->height = height;
     }
    void setRadius(double r)
    {
        this->radius = r;
        
    }
    void setHeight(double h)
    {
        this->height = h;
    }
    double getRadius()
    {
        return this->radius;
    }
    void getHeight()
    {
        cout<<"height ="<<this->height;
    }
    double getVolume()
    {
        this->result = this->pi * this->radius * this->radius * this->height;
        cout << "Volume of Cylinder : " << this->result << endl;
        return (this->result);
    }
    void PrintVolume()
    {
        cout << "****************" << endl;
        cout << "Volume of Cylinder : " << this->result << endl;
    }
};
int main()
{ 
     Vcylinder v1,v2;
    while (true)
    {
        int choice;
        double value;
        double h, r;
       
        cout << "***Menu***" << endl;
        cout << "0.EXIT" << endl;
        cout << "1.Set Radius" << endl;
        cout << "2.Get Radius" << endl;
        cout << "3.Set Height" << endl;
        cout << "4.Get Height" << endl;
        cout << "5.Get Volume" << endl;
        cout << "6.Print Volume " << endl;
        cout << "7.Set Default Dimensions" << endl;
        cout << "Enter the choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "You are  Exiting " << endl;
            return 0;
            break;
        case 1:
            cout << "Enter Radius :" << endl;
            cin >> r;
            v1.setRadius(r);
            break;
        case 2:
            cout << " Radius: " <<v1.getRadius();
            break;
        case 3:
            cout << "Enter Height: " << endl;
            cin >> h;
            v1.setHeight(h);
            break;
        case 4:
            v1.getHeight() ;
            break;
        case 5:
            value=v1.getVolume();
            break;
        case 6:
            v1.getVolume();
            v1.PrintVolume();
            break;
        case 7:
            v2.getVolume();
            break;
        default :
            cout << "You enter invalid choice" << endl;
            break;
        }
    }

    return 0;
}
