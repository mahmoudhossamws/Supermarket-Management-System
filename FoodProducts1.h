#ifndef fproduct_h
#define fproduct_h
#include "Product1.h"
class FoodProduct:public Product
{
public:
	enum type
	{
		Vegetable, Fruit, Other
	};
	FoodProduct(string n, double p, int q, string ed, type t) :Product(n, p,q)
	{
		expirydate = ed;
		foodtype = t;
	}
	string getexpirydate()
	{
		return expirydate;
	}
	type gettype()
	{
		return foodtype;
	}
	void setexpirydate(string d)
	{
		expirydate = d;
	}
private:
	string expirydate;
	type foodtype;
};
#endif