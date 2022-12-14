int main()
{
     Person t;
     Seller s;  // object of seller
     Product p; // object of product
     int choice;
     while ((choice = menu()) != 0)
     {
          switch (choice)
          {
          case 1:

               s.accept(); // accepting the sellers details using base class function accept()

               break;

          case 2:
               p.acceptP(); // accepting the products using base class accept();

               break;

          case 3:
               s.sold_Products(); // Calling function of sold products
               break;

          case 4:
               p.displayP();
               break;

          default:
               cout << "wrong choice" << endl;
          }
     }
     cout << "Thank You for using Application:" << endl;
     return 0;
}