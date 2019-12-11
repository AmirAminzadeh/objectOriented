//Name: Amir Aminzadeh
//Student number: 126554187
//Student email: aaminzadeh2@myseneca.ca
//Section: SEE

#ifndef SALE_H
#define SALE_H
#include <vector>
#include "Product.h"

namespace sict
{
	class Sale {

		std::vector<iProduct*>  proObj;

	public:

		Sale(const char* nameOfFile);
		void display(std::ostream& os) const;

	};
}



#endif 

