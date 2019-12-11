//Name: Amir Aminzadeh
//Student number: 126554187
//Student email: aaminzadeh2@myseneca.ca
//Section: SEE

#ifndef KVPAIR_H
#define KVPAIR_H

extern int fieldWidth;
namespace sict
{

	template<typename K, typename V>
	class KVPair {

		K src_key;
		V src_value;

	public:

		KVPair() {};
		KVPair(const K& key, const V& value) {

			src_key = key;
			src_value = value;

		};

		//a templated query that inserts into the output stream os the current object’s key(left - justified),
		//a single space, a colon, a single space, the object’s value and the object’s value converted 
		//through the function f(both right justified) as shown above.If the current object is in a safe 
		//empty state, this query does nothing.The field width for the object’s values is externally defined.
		template<typename F>
		void display(std::ostream& os, F f) const {
			os << std::left << std::setw(fieldWidth) << src_key << " : "
				<< std::right << std::setw(fieldWidth) << src_value <<
				std::setw(fieldWidth) << f(src_value) << std::endl;

		};

	};

}
#endif