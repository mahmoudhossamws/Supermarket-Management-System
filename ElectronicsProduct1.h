#ifndef eproduct_h
#define eproduct_h
#include "Product1.h"
#include <string>
using namespace std;
class ElectronicsProduct : public Product
{
public:
	enum type
	{
		phone, laptop, watch
	};
	ElectronicsProduct(string n, double p, int q, int wd, string f, type t):Product(n,p,q)
	{
		warrantyyears = wd;
		factory = f;
		electronictype = t;
	}
	int getwarrantyyears()
	{
		return warrantyyears;
	}
	string getfactory()
	{
		return factory;
	}
	type getype()
	{
		return electronictype;
	}
	void setwarrantyyears(int n)
	{
		warrantyyears = n;
	}
	void setfactory(string n)
	{
		factory = n;
	}
private:
	// number of avaialable electronics is the same as quantity in base class
	//having 2 variabels for same thing is redundant
	int warrantyyears;
	string factory;

	type electronictype;
};
#endif