#include "Person.h"
using namespace std;

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