#ifndef product_h
#define product_h
#include <iostream>
#include <string>
#include <vector>
#include "Discount1.h"
using namespace std;
class Product
{
protected:
	//mutual variables for all products
	string name;
	double price;
	int quantity;
	double valuesaved;
	bool isbogo;
	string discount;
public:
	Product(string n, double p, int q)
	{
		name = n;
		price = p;
		quantity = q;
		valuesaved = 0;
		isbogo = false;
		discount = " ";
	}
	string getname()
	{
		return name;
	}
	string getdiscount()
	{
		return discount;
	}
	void addiscount(string n)
	{
		discount += "\n";
		discount += n;
	}
	double getprice()
	{
		return price;
	}
	void setname(string n)
	{
		name = n;
	}
	void setprice(double p)
	{
		price = p;
	}
	int getquantity()
	{
		return quantity;
	}
	void setquantity(int n)
	{
		quantity = n;
	}
	double getvaluesaved()
	{
		return valuesaved;
	}
	void increasevalue(double n)
	{
		valuesaved += n;
	}
	void bogo()
	{
		isbogo = true;
	}
	bool getisbogo()
	{
		return isbogo;
	}
};
#endif