#define _CRT_SECURE_NO_WARNINGS
#include "Grocery.h"

namespace sict
{

	Grocery::Grocery(const string & desc, double price, const string & taxable)
	{
		m_taxable = "";
		m_desc = desc;
		m_price = price;
		if (taxable[0] == 'H' || taxable[0] == 'P' || taxable[0] == ' ')
		{
			m_taxable = taxable;
		}
		else
		{
			string msg = "*unlisted tax symbol* : " + desc + " " + to_string(price) + " " + taxable;
			char* x = new char[msg.size() + 1];
			strcpy(x, msg.c_str());
			throw (x);
		}
	}

	Grocery::Grocery(Grocery && g)
	{
		if (this != &g)
		{
			m_desc = g.m_desc;
			m_taxable = g.m_taxable;
			m_price = g.m_price;
			g.m_desc = "";
			g.m_price = 0;
			g.m_taxable = "";
		}
	}

	void Grocery::display(ostream & os) const
	{
		os << setw(FWDescription) << left << m_desc;
		os << setw(FWPrice) << right << m_price << " " << m_taxable << endl;
	}
}