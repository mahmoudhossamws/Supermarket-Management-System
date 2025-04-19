#ifndef bproduct_h
#define bproduct_h
#include "Product1.h"
class BooksProduct :public Product 
{
private:
 //Title is the name in base class
	//having 2 variabels for same thing is redundant
	string author;
	string genre;
public:
	BooksProduct(string n,double p, int q, string a, string g) :Product(n, p,q)
	{
		author = a;
		genre = g;
	}
	string getauthor()
	{
		return author;
	}
	string getgenre()
	{
		return genre;
	}
};
#endif
