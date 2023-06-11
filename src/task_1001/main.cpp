/*
Эта задача настолько проста, что авторы даже поленились сочинить для нее условие!

Исходные данные
Входной поток содержит набор целых чисел Ai (0 ≤ Ai ≤ 1018), отделённых друг от друга 
произвольным количеством пробелов и переводов строк. Размер входного потока не превышает 256 КБ.

Результат
Для каждого числа Ai, начиная с последнего и заканчивая первым, в отдельной строке вывести 
его квадратный корень не менее чем с четырьмя знаками после десятичной точки.

Пример
исходные данные				результат
 1427  0   					2297.0716
   876652098643267843 		936297014.1164
5276538						0.0000
							37.7757
*/

#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>


int main()
{
	std::list<double> values;
	
	double v;
	while (std::cin >> v)
		values.push_back(v);

	for (auto it = values.crbegin(); it != values.crend(); ++it)
		std::cout << std::fixed << std::setprecision(4) << sqrt(*it) << std::endl;

	return 0;
}
