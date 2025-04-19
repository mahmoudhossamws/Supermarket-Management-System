#ifndef productmanager_h
#define productmanager_h
#include <vector>
#include "Product1.h"
#include "FoodProducts1.h"
#include "ElectronicsProduct1.h"
#include "BooksProduct1.h"
#include <algorithm> //to use sort
using namespace std;
template <class T>
class ProductManager
{
private:
	vector <T> items;
public:
	vector <T> getitems()
	{
		return items;
	}
	void add(T &item)
	{
		items.push_back(item);
	}
	void removelast()
	{
		items.pop_back();
	}
	void remove(T & item)
	{
		for (int i = 0; i < items.size(); i++)
		{
			if (items[i].getname() == item.getname())
			{
				items.erase(items.begin() + i);
					break;
			}
		}
	}
	void clear()
	{
		items.clear();
	}
	void  display()//The benefit of having base class here is to have only one function because names of functions are same for the base class
		//because having many specialized functions for same job is redundant
	{ // another solution is to have functions with same name to get title and number of avaialble electronics
		cout << "Product manager has:" << endl;
		for (int i = 0; i < items.size(); i++)
		{
			cout << items[i].getname() << "  Price: " << items[i].getprice() <<"   Quantity: "<<items[i].getquantity()<< endl;
		}
	}
	void sort(string sort_by)
	{
		if (sort_by == "price")
		{
			for (int i = 0; i < items.size() - 1; i++)
			{
				for (int j = 0; j < items.size() - i - 1; j++)
				{
					if (items[j].getprice() < items[j + 1].getprice())
					{
						T temp = items[j];
						items[j] = items[j + 1];
						items[j + 1] = temp;
					}
				}
			}
		}
		if (sort_by == "name")
		{
			for (int i = 0; i < items.size() - 1; i++)
			{
				for (int j = 0; j < items.size() - i - 1; j++)
				{
					if (items[j].getname() > items[j + 1].getname())
					{
						T temp = items[j];
						items[j] = items[j + 1];
						items[j + 1] = temp;
					}
				}
			}
		}
		if (sort_by == "quantity")
		{
			for (int i = 0; i < items.size() - 1; i++)
			{
				for (int j = 0; j < items.size() - i - 1; j++)
				{
					if (items[j].getquantity() < items[j + 1].getquantity())
					{
						T temp = items[j];
						items[j] = items[j + 1];
						items[j + 1] = temp;
					}
				}
			}
		}

	}
	void operator+(T & item)
	{
		add(item);
	}
	void operator-(T &item)
	{
		remove(item);
	}
	friend ostream& operator<<(ostream& os, ProductManager<T>& manager) 
	{
		os << "Product manager has:" << endl;
		for (int i = 0; i < manager.getitems().size(); i++)
		{
			os << manager.getitems()[i].getname() << "   price: " << manager.getitems()[i].getprice() <<"   quantity:  "<<manager.getitems()[i].getquantity()<< endl;
		}
		return os;
	}
};


template <>
class ProductManager <ElectronicsProduct>
{
private:
	vector <ElectronicsProduct> items;
public:
	vector <ElectronicsProduct> getitems()
	{
		return items;
	}
	void add(ElectronicsProduct &item)
	{
		items.push_back(item);
	}
	void removelast()
	{
		items.pop_back();
	}
	void remove(ElectronicsProduct item)
	{
		for (int i = 0; i < items.size(); i++)
		{
			if (items[i].getname() == item.getname())
			{
				items.erase(items.begin() + i);
					break;
			}
		}
	}
	void clear()
	{
		items.clear();
	}
	void display()
		
	{
		cout << "Product manager has:" << endl;
		for (int i = 0; i < items.size(); i++)
		{
			cout << getitems()[i].getname() << "   price: " << getitems()[i].getprice() << "   quantity:  " << getitems()[i].getquantity();
			cout << "   Warranty Years: " << getitems()[i].getwarrantyyears() << endl;
		}
	}
	void sort (string sort_by)
	{
		if (sort_by == "price")
		{
			for (int i = 0; i < items.size() - 1; i++)
			{
				for (int j = 0; j < items.size() - i - 1; j++)
				{
					if (items[j].getprice() < items[j + 1].getprice())
					{
						ElectronicsProduct temp = items[j];
						items[j] = items[j + 1];
						items[j + 1] = temp;
					}
				}
			}
		}
		if (sort_by == "name")
		{
			for (int i = 0; i < items.size() - 1; i++)
			{
				for (int j = 0; j < items.size() - i - 1; j++)
				{
					if (items[j].getname() > items[j + 1].getname())
					{
						ElectronicsProduct temp = items[j];
						items[j] = items[j + 1];
						items[j + 1] = temp;
					}
				}
			}
		}
		if (sort_by == "quantity")
		{
			for (int i = 0; i < items.size() - 1; i++)
			{
				for (int j = 0; j < items.size() - i - 1; j++)
				{
					if (items[j].getquantity() < items[j + 1].getquantity())
					{
						ElectronicsProduct temp = items[j];
						items[j] = items[j + 1];
						items[j + 1] = temp;
					}
				}
			}
		}

	}
	void operator+(ElectronicsProduct& item)
	{
		add(item);
	}
	void operator-(ElectronicsProduct &item)
	{
		remove(item);
	}
	friend ostream& operator<<(ostream& os, ProductManager<ElectronicsProduct>& manager) {
		os << "Product manager has:" << endl;
		for (int i = 0;i< manager.getitems().size(); i++)
		{
			os << manager.getitems()[i].getname() << "   price: " << manager.getitems()[i].getprice() << "   quantity:  " << manager.getitems()[i].getquantity();
				os<<"   Warranty Years: " << manager.getitems()[i].getwarrantyyears() << endl;
		}
		return os;
	}
	int getmax()
	{
		int max = items[0].getwarrantyyears();
		for (int i = 0; i < items.size(); i++)
		{
			if (items[i].getwarrantyyears() > max)
			{
				max = items[i].getwarrantyyears();
			}
		}
		return max;
	}
	int getmin()
	{
		int min = items[0].getwarrantyyears();
		for (int i = 0; i < items.size(); i++)
		{
			if (items[i].getwarrantyyears() < min)
			{
				min = items[i].getwarrantyyears();
			}
		}
		return min;
	}
	double getavg()
	{
		double sum = 0;
		for (int i = 0; i < items.size(); i++)
		{
			sum += items[i].getwarrantyyears();
		}
		return sum / items.size();
	}
};
#endif