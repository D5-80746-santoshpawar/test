#include "../include/person.h"
#include "../include/product.h"
#include "../include/seller.h"

        Seller::Seller(){                                   //parameterless constructor            
            this->Seller_name="";
            this->Id=0;
        }

        Seller::Seller(string Seller_name, int Id){         //parameterize constructor
            this->Seller_name=Seller_name;
            this->Id=Id;
        }

        void Seller::addSeller(){                           //taking details of the seller
            cout<<"Enter Seller Name : "<<endl;
            cin>>this->Seller_name;
            cout<<"Enter Id : "<<endl;
            cin>>this->Id;
            product.addProduct();
            cout<<"-----------------------------"<<endl;
        }

        void Seller::displaySeller(Seller seller[]){        //displaying details of the seller
            cout<<"Seller Name is : "<<this->Seller_name<<endl;
            cout<<"Id is : "<<this->Id<<endl;
            cout<<"Products of the seller are : "<<endl;
            product.displayProduct(&product);
            cout<<"-----------------------------"<<endl;
        }

