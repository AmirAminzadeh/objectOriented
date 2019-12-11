//Name: Amir Aminzadeh
//Student number: 126554187
//Student email: aaminzadeh2@myseneca.ca
//Section: SEE

#ifndef KVLIST_H
#define KVLIST_H


#include "KVPair.h"

namespace sict
{

	template<typename T>
	class KVList {

		T* list;             //managing a dynamically allocated list of T objects.
		int numberOfList;
		int numberOfCurrentList;

	public:

		KVList() {};


		//a single-argument constructor that receives the number of objects in the list and allocates memory 
		//for those objects. If the number received is not positive-valued your constructor places the object 
		//in a safe empty state.
		KVList(int n) {
			if (n > 0) {

				numberOfList = n;
				numberOfCurrentList = 0;
				list = new T[n];

			}
			else
				throw "Exception: The number of elements received in the constructor is not positive-valued";
		}


		KVList(KVList&& moveList) {
			if (this != &moveList)
			{
				list = moveList.list;
				numberOfList = moveList.numberOfList;
				numberOfCurrentList = moveList.numberOfCurrentList;

				moveList.list = nullptr;
				moveList.numberOfList = 0;
				moveList.numberOfCurrentList = 0;
			}
		}


		~KVList() {
			delete[] list;
			list = nullptr;
		}


		//a subscripting operator that returns an unmodifiable reference to the i-th element in the list
		const T& operator[](size_t i) const {
			if (i > numberOfList)
				throw "Exception: The index passed to the subscripting operator is out-of-bounds";
			return list[i];
		}


		//a templated query that inserts into the output stream os on a separate line each object 
		//in the list
		template<typename F>
		void display(std::ostream& os, F f) const {
			for (int i = 0; i < numberOfList; i++)
				list[i].display(os, f);
		}

		//a modifier that receives an unmodifiable reference to a T object t and if there is room 
		//in the list, adds the object t to the list. If the list is full, this function does nothing.
		void push_back(const T& t) {
			if (numberOfCurrentList + 1 <= numberOfList)
				list[numberOfCurrentList] = t;

			++numberOfCurrentList;
		}

		//Your design disables copy and move assignment operations and copy construction of the list.
		KVList(const KVList&) = delete;
		KVList& operator=(KVList&&) = delete;
		KVList& operator=(const KVList&) = delete;

	};

}

#endif