#include <iostream>
#include <map>
#include <vector>

#include "MyAllocator.hpp"
#include "MyVector.hpp"


template<template<typename...> typename Map, typename... Subtypes>
void fillMapByFactorial(Map<Subtypes...> &map, std::size_t size)
{
	if (!size)
		return;
	
	int factorial = 1;
	map[0] = factorial;

	for (std::size_t i = 1; i < size; ++i)
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
void fillVectorByRange(Vector<Subtypes...> &vector, std::size_t size)
{
	for (std::size_t i = 0; i < size; ++i)
		vector.push_back(i);
}



template<template<typename...> typename Vector, typename... Subtypes>
void printVector(Vector<Subtypes...> &vector)
{
	for (std::size_t i = 0; i < vector.size(); ++i)
		std::cout << vector.at(i) << std::endl;
}



int main()
{
	const std::size_t size = 10;
	
	std::map<int, int> map1;
	fillMapByFactorial(map1, size);
	//printMap(map1);

	std::map<int, int, std::less<int>, MyAllocator<std::pair<const int, int>>> map2;
	fillMapByFactorial(map2, size);
	printMap(map2);

	MyVector<int> vector1;
	fillVectorByRange(vector1, size);
	//printVector(vector1);

	MyVector<int, MyAllocator<int>> vector2;
	fillVectorByRange(vector2, size);
	printVector(vector2);

	return 0;
}
