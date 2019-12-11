//Name: Amir Aminzadeh
//Student number: 126554187
//Student email: aaminzadeh2@myseneca.ca
//Section: SEE

#ifndef TAXABLE_H
#define TAXABLE_H

namespace sict
{

	class Taxable {

		float tax_rate;

	public:
		//A one-argument constructor that receives the prescribed tax rate and stores it in an unmodifiable 
		//instance variable.
		Taxable(float prescribedTaxRate) {

			tax_rate = prescribedTaxRate;
		}


		//A function call operator that receives a price and returns the sum of the price and the tax added 
		//to it.
		float operator()(float price) {

			return (price + ((price / 100)*(tax_rate * 100)));
		}
	};

}

#endif