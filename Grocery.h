#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
extern int FWPrice;
extern int FWDescription;

namespace sict
{


	class Grocery
	{
	private:
		string m_desc;
		double m_price;
		string m_taxable;
	public:
		Grocery(const string& desc, double price, const string& taxable);
		Grocery(const Grocery&) = delete;
		Grocery operator=(const Grocery&) = delete;
		Grocery(Grocery && g);
		void display(ostream &os) const;
	};

}