#ifndef discount_h
#define discount_h
#include<iostream>
#include<string>
#include <vector>
#include "Product1.h"
using namespace std;
template <class T>
class Discount 
{
private:
	double dispercent;
	string discounttype;
public:
	Discount (string tt="null", double percent=0)
	{
		discounttype = tt;
		dispercent = percent;
	}
    string gettype()
    {
        return discounttype;
    }
    double getpercent()
    {
        return dispercent;
    }
	void operator-(T &item)
	{
        if (discounttype == "percentage")
        {
            item.increasevalue(item.getprice() * (dispercent / 100));
            item.setprice(item.getprice() - (item.getprice() * (dispercent / 100)));
            item.addiscount("percentage : "+ to_string(dispercent));
        }
        else if (discounttype == "fixed amount")
        {
            item.increasevalue(dispercent);
            item.setprice(item.getprice() - dispercent);
            item.addiscount("fixed amount : " + to_string(dispercent));
        }
        else if (discounttype == "BOGO") {
            if (item.getquantity() == 0)
            {
                cout << "Cannot get one more. quantity is not enough";
            }
            else
            {
                item.increasevalue(item.getprice());
                item.setprice(item.getprice() / 2);
                item.setquantity(item.getquantity() - 1);
                item.bogo();
                item.addiscount("BOGO");
            }
        }
        else
        {
            item.increasevalue(item.getprice() * (dispercent / 100));
            item.setprice(item.getprice() - (item.getprice() * (dispercent/ 100)));
            item.addiscount("Coupon : " +discounttype+"  " + to_string(dispercent));
        }
  
	}
};

#endif