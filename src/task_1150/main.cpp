/*
Петя Васечкин решил пронумеровать страницы в своей тетради числами от 1 до N. 
Определите количество нулей, единиц, …, девяток, которые ему потребуются.

Исходные данные
Целое число N (1 ≤ N < 109).

Результат
Выведите 10 строк, первая из которых содержит необходимое количество нулей, 
вторая — единиц, …, десятая — девяток. 

Пример
исходные данные		результат
12					1
					5
					2
					1
					1
					1
					1
					1
					1
					1
*/

#include <iostream>


int countDigit0(int value)
{
	int result = 0;
	
	int factor = 1;
	while (factor <= value)
	{
		int ost = value % (factor * 10);
		int div = value / (factor * 10);

		result += (div - 1) * factor;
		if (ost / factor == 0)
			result += 1;
		else if (ost / factor > 0)
			result += factor;

		factor *= 10;
	}

	return result;
}



int countDigit(int value, int digit)
{
	int result = 0;
	
	int factor = 1;
	while (factor <= value)
	{
		int ost = value % (factor * 10);
		int div = value / (factor * 10);

		result += div * factor;
		if (ost / factor == digit)
			result += value % factor + 1;
		else if (ost / factor > digit)
			result += factor;

		factor *= 10;
	}

	return result;
}



int main()
{
	int n;
	std::cin >> n;
	
	std::cout << countDigit0(n) << std::endl;
	for (int i = 1; i < 10; i++)
		std::cout << countDigit(n, i) << std::endl;

	return 0;
}
