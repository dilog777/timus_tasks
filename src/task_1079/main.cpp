/*
Рассмотрим последовательность чисел ai, i = 0, 1, 2, …, удовлетворяющих следующим условиям:

    a0 = 0
    a1 = 1
    a2i = ai
    a2i + 1 = ai + ai + 1
для каждого i = 1, 2, 3, … .

Напишите программу, которая для заданного значения n находит максимальное среди чисел a0, a1, …, an.

Исходные данные
Входные данные состоят из нескольких тестов (не более 10). Каждый тест представляет собой строку, 
в которой записано целое число n (1 ≤ n ≤ 99 999). В последней строке входных данных записано число 0.

Результат
Для каждого n во вводе выведите соответствующее максимальное значение.

Пример
исходные данные		результат
5					3
10					4
0
*/

#include <algorithm>
#include <array>
#include <iostream>
#include <list>

static const int ARRAY_SIZE = 100000;



class SequenceValue
{
public:
	SequenceValue() {}
	
	int maxValue(int n)
	{
		if (n < 0 || n >= ARRAY_SIZE)
			return 0;
		
		if (n > _lastFilled)
			fillValues(n);

		int max = *std::max_element(_values.begin(), _values.begin() + n + 1);
		return max;
	}

private:
	std::array<int, ARRAY_SIZE> _values{ 0, 1 };
	int _lastIndex{ 1 };
	int _lastFilled{ 1 };

	void fillValues(int n)
	{
		for (int &i = _lastIndex; i <= n / 2; ++i)
		{
			_values[i * 2] = _values[i];
			_values[i * 2 + 1] = _values[i] + _values[i + 1];
		}
		_lastFilled = n + 1;
	}
};



int main()
{
	int n;
	SequenceValue sv;
	std::list<int> results;
	while (std::cin >> n)
	{
		if (n == 0)
			break;

		int max = sv.maxValue(n);
		results.push_back(max);
	}

	for (const auto &max : results)
		std::cout << max << std::endl;

	return 0;
}
