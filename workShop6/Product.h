//Name: Amir Aminzadeh
//Student number: 126554187
//Student email: aaminzadeh2@myseneca.ca
//Section: SEE

#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <fstream>
#include "iProduct.h"

namespace sict
{
	class Product : public iProduct {
		int productNumber;
		double priceBeforeTax;
	public:
		Product();
		Product(int , double );
		double price() const;
		void display(std::ostream& os) const;
	};


	//Derive a class named TaxableProduct from your Product class to add taxation functionality to
	//the hierarchy.
	class TaxableProduct : public Product {

		//Your derived class includes
		//an enumeration list of tax types and a class variable with corresponding rates
			//HST 0.13
			//PST 0.08
		double taxRate;
		enum class Tax { HST, PST };
	public:
		//A three-argument constructor that receives and stores the product number, its price
		//and its tax status.
		TaxableProduct(int, double, char);

		//a query that returns the price of a product tax included.
		double price() const;

		//a query that displays the information about the
		//product and appends the tax status as shown in the example above.
		void display(std::ostream&) const;
	};

	//this function reads a single record from file
	//object file, allocates memory for a product in the hierarchy, stores the information read
	//into the product object and returns its address.The information includes the product
	//number and price and optionally the tax status as shown in the sample input above.If
	//the record does not include a tax status character this function allocates memory for a
	//Product object.If the record has a tax status character this function allocates memory
	//for a TaxableProduct object.
	iProduct* readRecord(std::ifstream& file);
	std::ostream& operator<<(std::ostream& os, const iProduct& p);	
}


#endif 