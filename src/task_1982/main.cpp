/*
В некоторой стране n городов. Правительство решило электрифицировать все эти города. 
Для начала в k различных городах были построены электростанции. Другие города должны 
быть связаны с электростанциями линиями электропередач. Между любой парой городов i и j 
можно построить линию электропередач стоимостью cij рублей. После гражданской войны 
страна находится в глубоком кризисе, поэтому правительство решило построить всего лишь 
несколько линий электропередач. Конечно, после постройки линий должен существовать путь 
по ним от любого города до некоторого города с электростанцией. Найдите минимальную 
возможную стоимость постройки всех необходимых для этого линий электропередач.

Исходные данные
В первой строке записаны целые числа n и k (1 ≤ k ≤ n ≤ 100). Во второй строке записаны k 
различных целых чисел — номера городов с электростанциями. В следующих n строках записана 
таблица {cij} размера n × n, состоящая из целых чисел (0 ≤ cij ≤ 105). Гарантируется, что 
cij = cji, cij > 0 для i ≠ j, cii = 0.

Результат
Выведите минимальную стоимость электрификации всех городов.

Пример
исходные данные		результат
4 2					3
1 4
0 2 4 3
2 0 5 2
4 5 0 1
3 2 1 0

*/

#include <climits>
#include <iostream>
#include <set>

static const int CITIES_MAX = 100;
int electrification_cost[CITIES_MAX][CITIES_MAX];


int main()
{
	int n, k;
	std::cin >> n >> k;
	
	int e;
	std::set<int> electrified;
	for (int i = 0; i < k; ++i)
	{
		std::cin >> e;
		electrified.insert(e - 1);
	}
	
	int c;
	for (int row = 0; row < n; ++row)
	{
		for (int column = 0; column < n; ++column)
		{
			std::cin >> c;
			electrification_cost[row][column] = c;
		}
	}

	int sum_cost = 0;
	while (electrified.size() < n)
	{
		int min_cost = INT_MAX;
		int min_num = 0;

		for (int x = 0; x < n; ++x)
		{
			if (electrified.count(x))
			{
				for (int y = 0; y < n; ++y)
				{
					if (!electrified.count(y))
					{
						c = electrification_cost[x][y];
						if (c && c < min_cost)
						{
							min_cost = c;
							min_num = y;
						}
					}
				}
			}
		}

		electrified.insert(min_num);
		sum_cost += min_cost;
	}

	std::cout << sum_cost << std::endl;

	return 0;
}
