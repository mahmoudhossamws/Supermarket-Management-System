#ifndef order_h
#define order_h
#include <iostream>
#include "ShoppingCart1.h"
#include <vector>
using namespace std;
class Order
{
private:
	vector <Product> order;
	Discount<Product> discountsonorder [70];
	int arraysize;
	ShoppingCart<FoodProduct>* fp;
	ShoppingCart <ElectronicsProduct > * ep;
	ShoppingCart<BooksProduct>* bp;
	int id;
public:
	vector <Product> getitems()
	{
		return order;
	}
	Order(ShoppingCart<FoodProduct>& f, ShoppingCart <ElectronicsProduct >& e, ShoppingCart<BooksProduct>& b, int d)
	{
		fp = &f;
		ep = &e;
		bp = &b;
		id = d;
		arraysize = 0;
		for (int i = 0; i < fp->getcartsize(); i++)
		{
			order.push_back(fp->getcart()->at(i));
		}
		for (int i = 0; i < ep->getcartsize(); i++)
		{
			order.push_back(ep->getcart()->at(i));
		}
		for (int i = 0; i < bp->getcartsize(); i++)
		{
			order.push_back(bp->getcart()->at(i));
		}
	}
	void applynewdiscount(string t, double p) //discounts can be made before the order on items and also using this function
	{
		Discount <Product> d1(t, p);
		for (int i = 0; i < order.size(); i++)
		{
			d1 - order[i];
		}
		discountsonorder[arraysize] = d1;
		arraysize++;
	}
	double calculatetotal()
	{
		double total=0;
		for (int i = 0; i < order.size(); i++)
		{
			if (order[i].getisbogo())
			{
				total += 2* order[i].getprice();
			}
			else
			{
				total += order[i].getprice();
			}
		}
		return total;
	}
	double calculatetotalbefore()
	{
		double total = 0;
		for (int i = 0; i < order.size(); i++)
		{
			if (order[i].getisbogo())
			{
				total += 2 * order[i].getprice();
				total +=  order[i].getvaluesaved();
			}
			else
			{
				total += order[i].getprice();
				total += order[i].getvaluesaved();
			}
		}
		return total;
	}
	void display()
	{
		cout << "ORDER  " <<id<<" : "<< endl << endl;
		for (int i = 0; i < order.size(); i++)
		{
			if (order[i].getisbogo())
			{
				cout << " 2 <BOGO OFFER> ";
			}
			cout << order[i].getname() << endl << "price before: ";
			if (order[i].getisbogo())
			{
				cout << order[i].getprice()+(order[i].getvaluesaved()/2);
			}
			else
			{
				cout << order[i].getprice() + order[i].getvaluesaved();
			}
			cout<< endl
				<< "Price after: " << order[i].getprice() << endl << "Offer applied: " << endl
				<< order[i].getdiscount()<<endl<<endl;
		}
		cout <<endl<< "Total before: " << calculatetotalbefore() << endl << "Total after: " << calculatetotal() << endl
			<< "Order discounts: " << endl;
		for (int i = 0; i < arraysize; i++)
		{
			cout << discountsonorder[i].gettype();
			if (discountsonorder[i].getpercent() > 0)
			{
				cout << "    amount: " << discountsonorder[i].getpercent()<<endl;
			}
		}
		cout << endl << endl;
	}
};
#endif