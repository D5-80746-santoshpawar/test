#include "../include/person.h"
#include "../include/product.h"
#include "../include/seller.h"

Product::  Product(){                    //parameterless constructor
            this->id=0;
            this->product_name="";
            this->price=0.0;
        }

Product:: Product(int id, string product_name, double price){     //parameterize constructor
            this->id=id;
            this->product_name=product_name;
            this->price=price;
        }

       void Product:: addProduct(){                                //taking details of the product
            cout<<"Enter id : "<<endl;
            cin>>this->id;
            cout<<"Enter product name : "<<endl;
            cin>>this->product_name;
            cout<<"Enter price : "<<endl;
            cin>>this->price;
            cout<<"-----------------------------"<<endl;
        }
      void Product:: displayProduct(Product product[]){          //displaying details of the seller
            cout<<"Product id : "<<this->id<<endl;
            cout<<"Product name : "<<this->product_name<<endl;
            cout<<"Price : "<<this->price<<endl;      
            cout<<"-----------------------------"<<endl;
        }