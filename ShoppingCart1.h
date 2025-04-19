#ifndef cart_h
#define cart_h
#include "ProductManager1.h"
using namespace std;
template <class T>
class ShoppingCart
{
private:
	vector<T> cart;
	ProductManager <T>* prp; // IT IS ASSOCIATION!
public:
	ShoppingCart(ProductManager<T> & p)
	{
		prp = &p;
	}
	void add(T & item)
	{
		bool found = false;
		int index = -1;
		for (int i = 0; i < prp->getitems().size(); i++)
		{
			if (prp->getitems()[i].getname() == item.getname())
			{
				if (prp->getitems()[i].getquantity() > 0)
					found = true;
				index = i;
			}
		}
		if (found)
		{
			cart.push_back(item);
			prp->getitems()[index].setquantity(prp->getitems()[index].getquantity() - 1);
		}
	}
	void remove(T & item)
	{
		for (int i = 0; i < cart.size(); i++)
		{
			if (cart[i].getname() == item.getname())
			{
				cart.erase(cart.begin() + i);
				prp->getitems()[i].setquantity(prp->getitems()[i].getquantity() + 1);
				break;
			}
		}
	}
	vector<T>* getcart()
	{
		return &cart;
	}
	size_t getcartsize()
	{
		return cart.size();
	}
};
#endif
