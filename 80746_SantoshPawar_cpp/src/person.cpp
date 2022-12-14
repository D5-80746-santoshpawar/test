#include "../include/person.h"
#include "../include/product.h"
#include "../include/seller.h"

Person::Person(){                      //parameterless constructor
            this->name="";
        }

Person::Person(string name){           //parameterize constructor
            this->name=name;
        }

void  Person::menue(){                                     //defining function menue to make a code menue driven
    int choice;
    Seller *seller = new Seller[5];
    Product *product = new Product[3];
    do
    {
    cout<<"Enter your choise from bellow : "<<endl;
    cout<<"0. Exit : "<<endl;
    cout<<"1. Add Seller : "<<endl;
    cout<<"2. Add Product : "<<endl;
    cout<<"3. Display products sold by specific seller : "<<endl;
    cout<<"4. Display All Sellers : "<<endl;
    cout<<"5. Display All Products : "<<endl;
    cin>>choice;

    switch (choice)
    {
    case 0:
        cout<<"You have successfully exited the program !!"<<endl;
        break;

    case 1:                               //Add Seller
        for (int i=0;i<2;i++){
        seller[i].addSeller();
        }
        break;
    
    case 2:                               //Add Product
        for (int i=0;i<2;i++){
        product[i].addProduct();
        }
        break;

    case 3:
        seller->displaySeller(seller);                               //Display products sold by specific seller
        break;

    case 4:                               //Display All Sellers
        for (int i=0;i<2;i++){
        seller[i].displaySeller(seller);
    }

        break;

    case 5:                              //Display All Products
        for (int i=0;i<2;i++){
        product[i].displayProduct(product);
        }
        break;

    default:
        cout<<"Invalid choice !!"<<endl;
        break;
    }
    } while (choice!=0);
}