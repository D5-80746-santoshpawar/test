#include <iostream>
using namespace std;
class Volume
{
private:
    int length;
    int breadth;
    int height;
    int Result;

public:
    Volume()
    {
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }
    Volume(int length, int breadth, int height)
    {
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }
    void AcceptDimension()
    {
        cout << "__________****_____________" << endl;
        cout << "Enter the length" << endl;
        cin >> this->length;
        cout << "Enter the breadth" << endl;
        cin >> this->breadth;
        cout << "Enter the height" << endl;
        cin >> this->height;
    }
    void CalculateVolume()
    {

        this->Result = (this->length * this->breadth * this->height);
        cout << "Volume of box: " << Result << endl;
    }
    void SetDefault()
    {
        Volume vol(0, 0, 0);
        vol.CalculateVolume();
    }
};
int main()
{

    while (true)
    {
        int choice;
        Volume v1;
        cout << "****Menu****" << endl;
        cout << "0.EXIT" << endl;
        cout << "1.Accept Dimension of Box" << endl;
        cout << "2.Calculate Volume of Box & Print" << endl;
        cout << "3.Result of Default Dimensions" << endl;
        cout << "Enter the choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "You are  Exiting " << endl;
            return 0;
            break;
        case 1:
            v1.AcceptDimension();

            break;
        case 2:
            v1.CalculateVolume();
            break;
        case 3:

            v1.SetDefault();
            break;
        default:
            cout << "You enter invalid choice" << endl;
            break;
        }
    }

    return 0;
}

