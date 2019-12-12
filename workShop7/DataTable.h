//Name: Amir Aminzadeh
//Student number: 126554187
//Student email: aaminzadeh2@myseneca.ca
//Section: SEE


#ifndef DATATABLE_H
#define DATATABLE_H

#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>



extern int FW;
extern int ND;

namespace sict
{
	template <class T>
	class DataTable {
		std::vector<T> xData;
		std::vector<T> yData;

		T accumulatedxDatas{};
		T accumulatedyDatas{};
		T xMean{};             // x mean -- the average of all values in related to x
		T yMean{};             // y mean -- the average of all values in related to y
		T YstandardDeviation{};// standard deviation -- the spread of the numbers away from their mean
		T XYslope{};           // slope – the slope of the line in the x-y plane
		T Yintercept{};        //y_intercept – the y value of the line where it crosses the y-axis in the x-y plane
		T yMedian{};           //the middle number in the sorted set of the values

		int numOfRecords = 0;

	public:

		//A one-argument constructor that receive a reference to an std::ifstream object, read all
		//records from the object and stores them in the most appropriate STL container.
		DataTable(std::ifstream &fileObj) {
			xData.clear();
			yData.clear();
			std::string temp;

			T tempNum = 0;
			T tempPrice = 0.0;

			if (fileObj.is_open()) {
				while (!fileObj.eof() && fileObj.good()) {
					std::getline(fileObj, temp, '\n');

					size_t positionFirstSpace = temp.find_first_of(' ');

					tempPrice = std::stof(temp.substr(0, positionFirstSpace));
					tempNum = std::stof(temp.substr(positionFirstSpace, temp.length()));

					xData.push_back(tempPrice);
					yData.push_back(tempNum);

					temp.clear();
					tempNum = 0;
					tempPrice = 0.0f;

					numOfRecords++;
				}
			}

			accumulatedxDatas = std::accumulate(xData.begin(), xData.end(), 0.0);
			accumulatedyDatas = std::accumulate(yData.begin(), yData.end(), 0.0);

			xMean = accumulatedxDatas / xData.size();
			yMean = accumulatedyDatas / yData.size();

			{
				T position1{};

				std::for_each(yData.begin(), yData.end(), [&](T interValue) { position1 += (pow((interValue - yMean), 2)); });

				YstandardDeviation = sqrt(position1 / (yData.size() - 1));
			}

			{
				std::vector<T> temp;
				temp = yData;
				size_t sizeOfVector = std::size(temp);
				std::sort(temp.begin(), temp.end());
				yMedian = temp.at(sizeOfVector / 2);
			}

			{
				T position1{};
				for (size_t i = 0; i < xData.size(); i++) {
					position1 += xData.at(i) * yData.at(i);
				}

				T position2{};
				position2 = accumulatedxDatas * accumulatedyDatas;

				T position3{};
				std::for_each(xData.begin(), xData.end(), [&](T interValueue) { position3 += (interValueue * interValueue); });

				T position4{};
				position4 = accumulatedxDatas * accumulatedxDatas;

				XYslope = ((numOfRecords * position1) - (position2)) / ((numOfRecords * position3) - (position4));
			}

			{
				Yintercept = (accumulatedyDatas - XYslope * accumulatedxDatas) / numOfRecords;
			}
		}

		//a query that displays the x - y data in the
		//format shown above.Use the field width and precision specified in w7.
		void displayData(std::ostream &os) const
		{
			int fieldWidth = FW;
			int precision = ND;

			if (numOfRecords == 0)
			{
				throw("ERROR: container is empty!");
			}
			else
			{
				os << "Data Values"
					<< "\n------------" << std::endl;

				os << std::right << std::fixed
					<< std::setw(fieldWidth)
					<< "x"
					<< std::setw(fieldWidth)
					<< " y"
					<< std::endl;

				for (int i = 0; i < numOfRecords; i++)
				{
					os << std::right << std::fixed
						<< std::setw(fieldWidth)
						<< std::setprecision(precision) << xData.at(i)
						<< std::setw(fieldWidth)
						<< std::setprecision(precision) << yData.at(i)
						<< std::endl;
				}
			}
		}



		//a query that displays the statistics for
		//the current object in the format shown above.Use the field width and precision
		//specified in w7.
		void displayStatistics(std::ostream &os) const
		{
			int precision = ND;

			os << "\nStatistics"
				<< "\n----------" << std::endl;

			os << std::left << std::setw(12) << "  y mean" << std::left << std::setw(3) << "=" << std::right << std::setw(7) << std::setprecision(precision) << yMean << std::endl;
			os << std::left << std::setw(12) << "  y sigma" << std::left << std::setw(3) << "=" << std::right << std::setw(7) << std::setprecision(precision) << YstandardDeviation << std::endl;
			os << std::left << std::setw(12) << "  y median" << std::left << std::setw(3) << "=" << std::right << std::setw(7) << std::fixed << std::setprecision(4) << yMedian << std::endl;
			os << std::left << std::setw(12) << "  slope" << std::left << std::setw(3) << "=" << std::right << std::setw(7) << std::setprecision(precision) << XYslope << std::endl;
			os << std::left << std::setw(12) << "  intercept" << std::left << std::setw(3) << "=" << std::right << std::setw(7) << std::setprecision(precision) << Yintercept << std::endl;
		}
	};
}

#endif 