/*
Вы наверняка уже знаете, что Алексей — серьёзный математик, и он любит решать 
серьёзные задачи. Вот ещё одна из этих задач.

Даны три неотрицательных числа a, b, c. Нужно расставить их в некотором порядке 
и поставить между ними знаки +, − или × таким образом, чтобы результат получившегося 
арифметического выражения был минимален. Между каждой парой соседних чисел должен быть 
один знак, унарный минус и скобки использовать нельзя. Приоритет операций стандартный 
(сначала умножение).

Исходные данные
Даны целые неотрицательные числа a, b, c в неубывающем порядке (0 ≤ a ≤ b ≤ c ≤ 100), каждое в отдельной строке.

Результат
Выведите одно целое число — минимальное значение выражения.

Пример
исходные данные		результат
1					-5
2
3

*/

#include <iostream>


int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;
	
	int result = a - std::max(b + c, b * c);
	std::cout << result << std::endl;

	return 0;
}
