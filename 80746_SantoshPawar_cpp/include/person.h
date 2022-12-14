#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

class Person{                        //Base class
    private:
        string name;

    public:
        Person();                    //parameterless constructor
        Person(string name); 
        void menue();        //parameterize constructor
};






















#endif