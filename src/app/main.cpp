#include <iostream>
#include <map>
#include <vector>

#include "MyAllocator.hpp"
#include "MyVector.hpp"


template<template<typename...> typename Map, typename... Subtypes>
void fillMapByFactorial(Map<Subtypes...> &map, int size)
{
	int factorial = 1;
	map[0] = factorial;

	for (int i = 1; i < size; ++i)
	{
		factorial = factorial * i;
		map[i] = factorial;
	}
}



template<template<typename...> typename Map, typename... Subtypes>
void printMap(Map<Subtypes...> &map)
{
	for (const auto &pair : map)
		std::cout << pair.first << " " << pair.second << std::endl;
}



template<template<typename...> typename Vector, typename... Subtypes>
void fillVectorByRange(Vector<Subtypes...> &vector, int size)
{
	for (int i = 0; i < size; ++i)
		vector.push_back(i);
}



template<template<typename...> typename Vector, typename... Subtypes>
void printVector(Vector<Subtypes...> &vector)
{
	for (const auto &value : vector)
		std::cout << value << std::endl;
}



int main()
{
	std::map<int, int> map1;
	fillMapByFactorial(map1, 10);

	std::map<int, int, std::less<int>, MyAllocator<std::pair<const int, int>>> map2;
	fillMapByFactorial(map2, 10);
	printMap(map2);

	MyVector<int> vector1;
	fillVectorByRange(vector1, 10);
	//printVector(vector1);

//	for (const auto &value : vector1)
//		std::cout << value << std::endl;

	MyVector<int, MyAllocator<int>> vector2;
	fillVectorByRange(vector2, 10);

	return 0;
}
