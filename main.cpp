#include <iostream>
#include <string>
#include <vector>
#include "BooksProduct1.h"
#include "Discount1.h"
#include "ElectronicsProduct1.h"
#include "FoodProducts1.h"
#include "Order1.h"
#include "Product1.h"
#include "ProductManager1.h"
#include "ShoppingCart1.h"
using namespace std;
void displaydiscounts(vector <Order> & discounteditems)
{
    cout << "discounts history:" << endl;
    double sum = 0;
    for (int k = 0; k < discounteditems.size(); k++)
    {
        for (int i = 0; i < discounteditems[k].getitems().size(); i++)
        {
            cout << "product Name: " << discounteditems[k].getitems()[i].getname() << endl << "Discounts applied: "
                << discounteditems[k].getitems()[i].getdiscount() << "  Money saved: " << discounteditems[k].getitems()[i].getvaluesaved() << endl << endl;
        }        
        for (int i = 0; i < discounteditems[k].getitems().size(); i++)
        {
            sum += discounteditems[k].getitems()[i].getvaluesaved();
        }
    }
    cout << "Total money lost for company:  ";
    cout << sum;
}
void randomid(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        bool isUnique = false;
        int randomNumber;

        while (!isUnique)
        {
            randomNumber = rand() % 401 + 200;

            // Check if the generated number already exists in the array
            isUnique = true;
            for (int j = 0; j < i; ++j) {
                if (array[j] == randomNumber) {
                    isUnique = false;
                    break;
                }
            }
        }

        // Assign the unique random number to the array
        array[i] = randomNumber;
    }
}
int main()
{
    int idarray[50];
    randomid(idarray, 50);
    vector <Order> itemslog;
    BooksProduct book1("Pizza History", 20, 5, "mahmoud", "history");
    BooksProduct book2("The science of errors", 23.4, 2, "ahmed", "science");
    FoodProduct food1("Chicken Koki", 50, 20, "2-4-2024", FoodProduct::Other);
    FoodProduct food2("Carrot", 10, 10, "2-3-2024", FoodProduct::Vegetable);
    ElectronicsProduct e1("Dell laptop 2024", 2000, 8, 2, "El3ashr mn Ramdan", ElectronicsProduct::laptop);
    ElectronicsProduct e2("Iphone 40", 2320, 7, 1, "6 October", ElectronicsProduct::phone);
    ProductManager<BooksProduct> booksmanager;
  booksmanager + book1;
   booksmanager + book2;
    cout << booksmanager;
   booksmanager - book1;
   cout << booksmanager;
    booksmanager + book1;
    ProductManager<FoodProduct> fmanager;
    fmanager + food1;
    fmanager + food2;
    fmanager.sort("quantity");
    cout << fmanager;
    fmanager.sort("price");
    cout << fmanager;
    fmanager.sort("name");
    cout << fmanager;
    ProductManager<ElectronicsProduct> emanager;
    emanager + e1;
    emanager + e2;
    cout << emanager;
    emanager - e1;
    cout << emanager;
    emanager + e1;
    cout << "Max warranty: " << emanager.getmax() << endl << "Min warranty: " << emanager.getmin() << endl << "Avg warranty: " << emanager.getavg()<<endl;
    ShoppingCart<BooksProduct> sc1(booksmanager);
    ShoppingCart<FoodProduct> sc2(fmanager);
    ShoppingCart<ElectronicsProduct> sc3(emanager);
    sc1.add(book1);
    sc3.add(e2);
    Order order1(sc2, sc3, sc1, idarray[0]);
    ShoppingCart<BooksProduct> sc4(booksmanager);
    ShoppingCart<FoodProduct> sc5(fmanager);
    ShoppingCart<ElectronicsProduct> sc6(emanager);
    sc4.add(book2);
    sc5.add(food1);
    Order order2(sc5, sc6, sc4, idarray[1]);
    order1.display();
    order2.display();
    order1.applynewdiscount("BOGO", 0);
    order2.applynewdiscount("NileCart", 30);
    order1.display();
    order2.display();
    itemslog.push_back(order1);
    itemslog.push_back(order2);
    displaydiscounts(itemslog);
}