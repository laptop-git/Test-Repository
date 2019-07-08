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
//sort
#include <algorithm>

std::vector<int> GenerateRandVec(int, int, int);

int main() {

	std::vector<int> vecVals = GenerateRandVec(10, 1, 50);

	for(auto val: vecVals)
		std::cout << val << ", ";

	std::sort(vecVals.begin(), vecVals.end(),
			[](int x, int y){return (x < y);});

	std::cout << "\n***************\n";
	for(auto val: vecVals)
		std::cout << val << ", ";

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
