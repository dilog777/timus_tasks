/*
Среди заданного множества отрезков прямой с целочисленными координатами концов 
[Li, Ri] необходимо выбрать подмножество наименьшей мощности, целиком 
покрывающее отрезок [0, M], где M – целое положительное число.

Исходные данные
В первой строке записано целое число M (1 ≤ M ≤ 5000). В последующих строках 
перечислены пары целых чисел Li и Ri (−50000 ≤ Li < Ri ≤ 50000), каждая пара с 
новой строки, числа в парах отделены друг от друга одним пробелом. В последней 
строке записана пара нулей. Множество содержит не менее одного и не более 99999 
отрезков.

Результат
Программа должна формировать в первой строке требуемое минимальное число 
отрезков из исходного множества, необходимое для покрытия отрезка [0, M]. Далее 
должен следовать список покрывающего подмножества, упорядоченный по возрастанию 
координат левых концов отрезков. Список отрезков выводится в том же формате, что 
и во входe, завершающую пару нулей выводить не следует.

Если покрытие отрезка [0, M] исходным множеством отрезков [Li, Ri] невозможно, 
то следует вывести единственную фразу «No solution». 

Пример
исходные данные		результат
1					No solution
-1 0
-5 -3
2 5
0 0

--------------------------------
1					1
-1 0				0 1
0 1
0 0
*/

#include <iostream>
#include <list>


using Line = std::pair<int, int>;
using LineList = std::list<Line>;


LineList makeCoveredList(const LineList allLines, int min, int max)
{
	LineList result;
	auto lines = allLines;
	lines.sort();

	int lastEnd = min;
	int nextEnd = min;
	for (auto it = lines.begin(); it != lines.end(); ++it)
	{
		if (lastEnd >= max)
			break;

		for (auto jt = it; jt != lines.end(); ++jt)
		{
			auto &nextLine = *jt;
			if (nextLine.first > lastEnd)
				break;

			if (nextLine.second > nextEnd)
			{
				it = jt;
				nextEnd = nextLine.second;
			}
		}

		if (nextEnd == lastEnd)
			break;

		lastEnd = nextEnd;
		result.push_back(*it);
	}

	if (lastEnd < max)
		return {};

	return result;
}


int main()
{
	int M;
	std::cin >> M;

	LineList allLines;
	while (true)
	{
		Line line;
		std::cin >> line.first >> line.second;

		if (line.first == 0 && line.second == 0)
			break;

		allLines.push_back(line);
	}

	auto coveredLines = makeCoveredList(allLines, 0, M);
	if (!coveredLines.empty())
	{
		std::cout << coveredLines.size() << std::endl;
		for (const auto &line : coveredLines)
			std::cout << line.first << " " << line.second << std::endl;
	}
	else
		std::cout << "No solution";

	return 0;
}
