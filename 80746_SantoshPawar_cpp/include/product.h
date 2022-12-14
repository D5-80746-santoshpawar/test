#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
using namespace std;

class Product{
    private:
        int id;
        string product_name;
        double price;

    public:
        Product();                    //parameterless constructor
    

        Product(int id, string product_name, double price);     //parameterize constructor
            
        

        void addProduct();                          //taking details of the product
          

        void displayProduct(Product product[]);      //displaying details of the seller
         
        
};





#endif