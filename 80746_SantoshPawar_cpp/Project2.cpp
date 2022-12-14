
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

int menu()
{
     int choice;
     cout << "0. Exit" << endl;
     cout << "1. Add seller" << endl;
     cout << "2.Add product" << endl;
     cout << "3. Display Products sold  by seller:" << endl;
     cout << "4. Display  All Products :" << endl;

     cout << "enter your choice" << endl;
     cin >> choice;
     return choice;
}

int main()
{
     Person t;
     Seller s;  // object of seller
     Product p; // object of product
     int choice;
     while ((choice = menu()) != 0)
     {
          switch (choice)
          {
          case 1:

               s.accept(); // accepting the sellers details using base class function accept()

               break;

          case 2:
               p.acceptP(); // accepting the products using base class accept();

               break;

          case 3:
               s.sold_Products(); // Calling function of sold products
               break;

          case 4:
               p.displayP();
               break;

          default:
               cout << "wrong choice" << endl;
          }
     }
     cout << "Thank You for using Application:" << endl;
     return 0;
}
