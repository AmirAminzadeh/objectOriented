//Name: Amir Aminzadeh
//Student number: 126554187
//Student email: aaminzadeh2@myseneca.ca
//Section: SEE

#ifndef IPRODUCT_H
#define IPRODUCT_H
#include <iostream>
#include <fstream>



//Design and code an inheritance hierarchy named iProduct for holding data on products for sale.
//Your interface to the hierarchy uses the field width(int FW) defined outside the translation unit
//and specifies the following public member function requirements
namespace sict
{
	class iProduct {
	public:
		virtual double price() const = 0;
		virtual void display(std::ostream& os) const = 0;
	};

	iProduct* readRecord(std::ifstream& file);
	std::ostream& operator<<(std::ostream& os, const iProduct& p);
}



#endif 

