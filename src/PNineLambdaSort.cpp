//============================================================================
// Name        : PNineLambdaSort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
//rand
#include <ctime>
//sort, copy_if, for_each and transform
#include <algorithm>

std::vector<int> GenerateRandVec(int, int, int);

int main() {

	std::vector<int> vec1 = {1, 2, 3, 4, 5};
	std::vector<int> vec2 = {1, 2, 3, 4, 5};
	std::vector<int> vec3(5);
	transform(vec1.begin(), vec1.end(),
			vec2.begin(), vec3.begin(),
			[](int x, int y) { return x + y; });
	for(auto val: vec3)
		std::cout << val << ", ";
	std::cout << std::endl;

	std::vector<int> vecVals = GenerateRandVec(10, 1, 50);
	std::vector<int> tempVec;

	for(auto val: vecVals)
		std::cout << val << ", ";

	int divisor;
	std::cout << "\nList of values divisible by : ";
	std::cin >> divisor;

	std::copy_if(vecVals.begin(), vecVals.end(),
			std::back_inserter(tempVec),
			[&divisor](int x){ return (x % divisor == 0); });
	for(auto val: tempVec)
		std::cout << val << ", ";

	tempVec.clear();

	std::for_each(vecVals.begin(), vecVals.end(),
			[&](int x){ tempVec.push_back( x * 2 ); });
	std::cout << "\n****DOUBLE******\n";
	for(auto val: tempVec)
		std::cout << val << ", ";

	std::sort(vecVals.begin(), vecVals.end(),
			[](int x, int y){ return (x < y); });

	std::cout << "\n*****SORT******\n";
	for(auto val: vecVals)
		std::cout << val << ", ";

	tempVec.clear();

	std::copy_if(vecVals.begin(), vecVals.end(),
			std::back_inserter(tempVec),
			[](int x){ return (x % 2 == 0); });

	std::cout << "\n*****EVEN******\n";
	for(auto val: tempVec)
		std::cout << val << ", ";

	int iSum = 0;
	std::for_each(vecVals.begin(), vecVals.end(),
			[&](int x){ iSum += x; });
	std::cout << "\n*****SUM******\n";
	std::cout << "Sum = " << iSum;


	return 0;
}

std::vector<int> GenerateRandVec(int iSize, int iMin, int iMax){
	std::vector<int> iVec;
	int iRand;
	srand(time(NULL));

	for (int i = 0; i < iSize; i++){
		iRand = iMin + std::rand() % ((iMax + 1) - iMin);
		iVec.push_back(iRand);
	}

	return iVec;
}
