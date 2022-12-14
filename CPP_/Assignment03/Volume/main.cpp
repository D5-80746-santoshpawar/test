#include<iostream>
#include "Volume.h"
using namespace std;
int main()
{ 
     Volume v1,v2;
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
