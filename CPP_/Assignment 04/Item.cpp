#include <iostream>
#include <string.h>
using namespace std;
class Item
{
protected:
    int id;
    string title;
    float price;

public:
    Item()
    {
        this->id = 0;
        this->title = " ";
        this->price = 0.0;
    }
    Item(int id, string title, float price)
    {
        this->id = id;
        this->title = title;
        this->price = price;
    }
    virtual float getDiscount() = 0;
    float getFinalPrice()
    {
        return price - price * getDiscount();
    }
    virtual void displayItem()
    {
        cout << "Id :" << id << endl
             << "Title :" << title << endl
        << "Price :" << price << endl;
    }
   virtual void acceptItem()
    {
        cout << " Enter Id" << endl;
        cin >> id;
        cout << " Enter Title" << endl;
        cin >> title;
        cout << " Enter Price" << endl;
        cin >> price;
    }
};
class Book : public Item
{
private:
    string author;

public:
    Book()
    {
        this->author = " ";
    }
    Book(string author, int id, string title, float price) : Item(id, title, price)
    {
        this->author = author;
    }
    float getDiscount()
    {
        return 0.10f;
    }
    void acceptItem()
    {
        Item::acceptItem();
        cout << "Enter Author Name :" << endl;
        cin >> author;
    }
    void displyItem()
    {
        Item::displayItem();
        cout << "Author :" << author << endl;
    }
};
class Tape : public Item
{
private:
    string artist;

public:
    Tape()
    {
        this->artist = " ";
    }
    Tape(string artist, int id, string title, float price) : Item(id, title, price)
    {
        this->artist = " ";
    }
    float getDiscount()
    {
        return 0.5f;
    }
    void acceptItem()
    {
        Item::acceptItem();
        cout << "Enter Artist Name :" << endl;
        cin >> artist;
    }
    void displyItem()
    {
        Item::displayItem();
        cout << "Artist :" << artist << endl;
    }
};
int main()
{
    int value = 0;
    while (value < 3)
    {
        int choice;
        cout << "1.Book" << endl;
        cout << "2.Tape" << endl;
        cout << " Enter Your Choice" << endl;
        cin >> choice;
        Item *item=NULL;
        switch (choice)
        {
        case 1:
         item = new Book();
            break;
        case 2:
         item = new Tape();
            break;
        default:
        cout<<"Entered Wrong Choice"<<endl;
            break;
        }
        if (item!=NULL)
        {
        
          item->acceptItem();
          item->displayItem();
          cout<<"Final Price :"<<item->getFinalPrice();
        }
        cout<<endl;
        value++;
    }

    return 0;
}