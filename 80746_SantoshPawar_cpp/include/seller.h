#ifndef SELLER_H
#define SELLER_H
#include <iostream>
#include "../include/person.h"
#include "../include/product.h"
using namespace std;

class Seller : public Person{                        //using inheritance
    private:
        string Seller_name;
        double Id;
        Product product;                            //there is association present betn class Seller and class Product

    public:
        Seller();                                  //parameterless constructor            

        Seller(string Seller_name, int Id);         //parameterize constructor


        void addSeller();                      //taking details of the seller
          

        void displaySeller(Seller seller[]);      //displaying details of the seller

        

};

#endif