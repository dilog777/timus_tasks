/*
Шёл очередной контест Петрозаводских сборов. Игроки команды Psych Up быстро нашли 
простую задачу, и Федя сел за компьютер. Через пять минут решение было готово. Не 
тратя времени на тестирование, Федя отправил его на проверку и через несколько 
секунд получил вердикт Time Limit Exceeded.

Федя скомкал условие задачи и вышел из класса, хлопнув дверью. Что-то шло не так, 
нужно было развеяться. По пути в туалет он услышал разговор авторов контеста. Паша 
обсуждал со своим другом решение той самой задачи. Федя смог разобрать из их разговора 
только слова «собственные числа».

Федя подумал и решил, что у него, конечно же, есть собственные числа. Например, дата 
рождения, номер квартиры, оценка на последнем экзамене, количество поездок на соревнования. 
Но ведь контест командный. А что такое собственные числа команды? Естественно, что число 
является собственным для команды, если оно собственное для каждого из её участников. С 
такими радостными мыслями Федя направился назад в аудиторию.

Исходные данные
Входные данные состоят из трёх блоков по две строки. Первая строка каждого блока 
содержит целое число n —количество собственных чисел очередного игрока (1 ≤ n ≤ 4 000). 
Во второй строке блока записано n целых различных чисел в порядке возрастания — собственные 
числа очередного игрока. Все собственные числа — целые, положительные и не превосходят 109.

Результат
Выведите количество собственных чисел команды Psych Up.

Пример
исходные данные		результат
5					3
13 20 22 43 146
4
13 22 43 146
5
13 43 67 89 146
*/

#include <iostream>
#include <list>


int main()
{
	std::list<int> commonValues;
	for (int person = 0; person < 3; ++person)
	{
		int n;
		std::cin >> n;

		int value;
		std::list<int> personalValues;
		for (int i = 0; i < n; ++i)
		{
			std::cin >> value;
			personalValues.push_back(value);
		}

		if (person == 0)
		{
			commonValues = personalValues;
		}
		else
		{
			auto notContainsValue = [personalValues](int value) -> bool
			{
				auto it = std::find(personalValues.begin(), personalValues.end(), value);
				return it == personalValues.end();
			};
			
			
			auto it = std::remove_if(commonValues.begin(), commonValues.end(), notContainsValue);
			commonValues.erase(it, commonValues.end());
		}
	}

	std::cout << commonValues.size() << std::endl;

	return 0;
}
