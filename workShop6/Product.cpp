//Name: Amir Aminzadeh
//Student number: 126554187
//Student email: aaminzadeh2@myseneca.ca
//Section: SEE

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Product.h"


extern int FW;

namespace sict
{
	
	Product::Product() {
		productNumber = 0;
		priceBeforeTax = 0;
	}


	Product::Product(int numberPro, double costProduct) {
		productNumber = numberPro;
		priceBeforeTax = costProduct;
	}


	double Product::price() const {
		return priceBeforeTax;
	}

	//a query that displays the information about the
	//product.Use the field width defined in the supplied w6 module.
	void Product::display(std::ostream & os) const {
		//int FW = 10; because of extern int FW;
		os << std::setw(FW) << productNumber << std::setw(FW) << priceBeforeTax;
	}

	

	TaxableProduct::TaxableProduct(int productNumber, double price, char status) : Product(productNumber, price)
		, taxRate(status == 'H' ? 0.13 : 0.08)
	{
	}

	
	double TaxableProduct::price() const {

		return Product::price() * (1 + taxRate);
	}

	
	void TaxableProduct::display(std::ostream & os) const {
		Product::display(os);

		if (taxRate == 0.13) {
			os << " HST";
		}
		else {
			os << " PST";
		}
	}

	
	iProduct* readRecord(std::ifstream & file) {
		iProduct* product = nullptr;

		std::string line = {};
		int numberOfProduct = 0;
		double price = 0.0;
		char tax = {};

		while (std::getline(file, line, '\n')) {
			size_t count = std::count(line.begin(), line.end(), ' ');	
			std::stringstream stream(line);
			if (count == 2) {
				stream >> numberOfProduct >> price >> tax;
				product = new TaxableProduct(numberOfProduct, price, tax);
				break;
			}
			else {
				stream >> numberOfProduct >> price;
				product = new Product(numberOfProduct, price);
				break;
			}
		}

		return product;
	}



	std::ostream & operator<<(std::ostream & os, const iProduct & p) {
		p.display(os);
		return os;
	}
}