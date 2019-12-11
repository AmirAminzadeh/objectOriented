//Name: Amir Aminzadeh
//Student number: 126554187
//Student email: aaminzadeh2@myseneca.ca
//Section: SEE

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Sale.h"
#include "Product.h"


extern int FW;

namespace sict
{

	//A single argument constructor that receives the address of an unmodifiable C-style null
	//terminated string that contains the name of the file holding records of iProduct type.
	//This function opens the file, reads one record from the file, moves that record into an
	//STL container and keeps reading records until there are none left to be read.If this
	//function fails to open the file, it throws an exception with an appropriate message.
	Sale::Sale(const char* nameOfFile) {
		if (nameOfFile != nullptr && nameOfFile[0] != '\0') {
			std::string buffer;
			size_t count = 0;
			std::ifstream fs;
			fs.open(nameOfFile);


			if (fs.is_open()) {
				while (std::getline(fs, buffer))
					count++;
				fs.clear();
				fs.seekg(0, std::ios::beg);
				for (size_t i = 0; i < count; i++)
					proObj.push_back(readRecord(fs));
				fs.close();
			}
			else {
				throw "File is not changed";
			}
		}

		else {
			throw "There is not the file";
		}
	}


	void Sale::display(std::ostream & os) const {

		//int FW = 10;
		os << "\nProduct No" << std::setw(FW) << "Cost" << ' ' << "Taxable" << std::endl;
		double total = 0.0;
		for (auto& i : proObj) {
			os << *i;
			os << std::fixed << std::setprecision(2);
			total += i->price();
			os << std::endl;
		}
		os << std::setw(FW) << "Total" << std::setw(FW) << total << std::endl;
	}
}

