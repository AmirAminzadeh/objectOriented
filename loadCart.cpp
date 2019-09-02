#include <vector>
#include <string>
#include <fstream>
#include "Grocery.h"

using namespace std;
using namespace sict;

void loadCart(const char* filename, vector<Grocery>& cart)
{
	ifstream file(filename);
	if (!file) exit(1);
	while (file)
	{
		string description;
		double price;
		string tax = " ";
		file >> description >> price;
		bool isTaxed = file.get() != '\n';
		if (isTaxed)
		{
			file >> tax;
		}
		try
		{
			Grocery g(description, price, tax);
			cart.push_back(move(g));
		}
		catch (const char* msg)
		{
			//cout << msg << description << " " << price << " " << tax << endl;
			cout << msg << endl;
		}
	}
	file.close();
}
