#ifndef Person_H
#define Person_H
#include <iostream>
using namespace std;
class Person
{
private:
     string Name;

public:
     Person()
     {
          this->Name = Name;
          cout << "" << endl;
     }
     virtual void accept()
     {
          cout << "enter Name = ";
          cin >> this->Name;
     }
     virtual void display()
     {
          cout << "Name = " << this->Name << endl;
     }
};

class Seller : public Person
{
private:
     string Seller_Name;
     int id;
     int sold;

public:
     void accept()
     {
          Person::accept();

          cout << "enter the id:" << endl;
          cin >> this->id;

          cout << "Give the products sold by seller:" << endl;
          cin >> this->sold;
     }

     void display()
     {

          Person::display();
          cout << "sellers name:" << this->Seller_Name;
          cout << "id:" << this->id;
     }
     void sold_Products()
     {
          cout << "total products sold:" << this->sold;
     }
};

class Product : public Person, public Seller    // multi-level inheritance
{
private:
     int id;
     string Product_Name;
     double Price;

public:
     void acceptP()                             // function overriden
     {
          cout << "enter Product name:" << endl;
          cin >> this->Product_Name;

          cout << "Enter the price:" << endl;
          cin >> this->Price;
     }

    void displayP()                    // function for displaying products
     
     {

         cout << "product name:" << Product_Name<<endl;
         cout << "Price:" << Price<<endl;
     }
};
#endif