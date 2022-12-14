#include <iostream>
using namespace std;
class Volume
{
private:
    double radius;
    double height;
    double result;
    const double pi = 3.14;

public:
    Volume();
    Volume(double radius, double height) : pi(3.14);
    void setRadius(double r);
    void setHeight(double h);
    double getRadius();
    double getVolume();
    void PrintVolume();
};