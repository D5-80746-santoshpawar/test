#include "Volume.h"
volume::Volume()
{
    this->radius = 0;
    this->height = 0;
}
Volume::Volume(double radius, double height) : pi(3.14)
{
    this->radius = radius;
    this->height = height;
}
void Volume::setRadius(double r)
{
    this->radius = r;
}
void Volume::setHeight(double h)
{
    this->height = h;
}
double Volume::getRadius()
{
    return this->radius;
}
void Volume::getHeight()
{
    cout << "height =" << this->height;
}
double Volume::getVolume()
{
    this->result = this->pi * this->radius * this->radius * this->height;
    cout << "Volume of Cylinder : " << this->result << endl;
    return (this->result);
}
void Volume::PrintVolume()
{
    cout << "****************" << endl;
    cout << "Volume of Cylinder : " << this->result << endl;
}