/*
Даны N отрезков на прямой. Каждый отрезок задан координатами своих концов Ai и 
Bi (Ai < Bi, 1 ≤ i ≤ N). Некоторые отрезки могут пересекаться. Напишите 
программу, которая уберёт минимальное количество отрезков из заданных, так что 
никакие два отрезка из оставшихся не будут иметь общей внутренней точки.

Исходные данные
Первая строка ввода содержит целое число N (1 ≤ N ≤ 99). Каждая из следующих N 
строк содержит целые числа Ai и Bi (−999 ≤ Ai < Bi ≤ 999).

Результат
В первой строке выведите целое число P, равное количеству отрезков, которые 
остались после того, как ваша программа убрала лишние отрезки. Следующие P строк 
должны содержать координаты левых и правых концов оставленных отрезков. 
Координаты должны быть разделены одним пробелом. Отрезки должны быть выведены в 
порядке возрастания координат левых концов. Если задача имеет более одного 
решения, выведите любое из них.

Пример

Пример
исходные данные		результат
3					2
3 6					1 3
1 3					3 6
2 5					

*/

#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <vector>



struct Line
{
	int _start{ 0 };
	int _end{ 0 };

	bool operator<(const Line &r) const
	{
		if (_start != r._start)
			return _start < r._start;

		return _end < r._end;
	}

	bool operator==(const Line &r) const
	{
		return _start == r._start
			&& _end == r._end;
	}
};

using IntersectionMap = std::map<int, std::list<int>>;

IntersectionMap makeIntersectionMap(const std::vector<Line> &lines)
{
	IntersectionMap result;

	int size = static_cast<int>(lines.size());
	for (int i = 0; i < size; ++i)
		result[i] = std::list<int>();

	for (int i = 0; i < size; ++i)
	{
		auto& line1 = lines[i];
		for (int j = i + 1; j < size; ++j)
		{
			auto& line2 = lines[j];
			if (line1._end <= line2._start)
				break;

			result[i].push_back(j);
			result[j].push_back(i);
		}
	}

	return result;
}

int findMinIntersectionLine(const IntersectionMap &map)
{
	int minIndex = 0;
	size_t minSize = INT_MAX;
	for (const auto &[index, usageList] : map)
	{
		size_t listSize = usageList.size();
		if (listSize < minSize)
		{
			minIndex = index;
			minSize = listSize;
		}
	}
	return minIndex;
}

void removeLineIntersections(IntersectionMap& map, int lineIndex)
{
	auto &usageList = map[lineIndex];
	for (const auto &idx : usageList)
		map.erase(idx);
	
	map.erase(lineIndex);
}



int main()
{
	int n;
	std::cin >> n;

	// Input
	int start, end;
	std::vector<Line> lines;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> start >> end;
		if (start > end)
			std::swap(start, end);

		lines.push_back({ start, end });
	}

	// Processing
	std::sort(lines.begin(), lines.end());
	lines.erase(unique(lines.begin(), lines.end()), lines.end());

	std::list<int> resultLines;
	auto map = makeIntersectionMap(lines);
	while (!map.empty())
	{
		int index = findMinIntersectionLine(map);
		resultLines.push_back(index);
		removeLineIntersections(map, index);
	}

	resultLines.sort();

	// Output
	std::cout << resultLines.size() << std::endl;
	for (const auto& index : resultLines)
	{
		auto &line = lines[index];
		std::cout << line._start << " " << line._end << std::endl;
	}

	return 0;
}
