/*
После личного первенства довольные, но голодные программисты зашли в ресторан 
«Уральские бифштексы» и заказали себе n фирменных бифштексов. Для того чтобы 
приготовить бифштекс, повар должен прожарить каждую из его сторон на сковороде 
в течение одной минуты.

К сожалению, у повара есть только одна сковорода, и на ней можно одновременно жарить 
не более k бифштексов. Определите, сколько минут понадобится повару, чтобы выполнить 
заказ программистов.

Исходные данные
В единственной строке через пробел записаны целые числа n и k (1 ≤ n, k ≤ 1000).

Результат
Выведите минимальное количество минут, за которое повар сможет приготовить n бифштексов.

Пример
исходные данные		результат
3 2					3

*/

#include <iostream>


int main()
{
	int n, k;
	std::cin >> n >> k;
	
	int result;
	if (n <= k)
	{
		result = 2;
	}
	else
	{
		int sides = n * 2;
		result = sides / k;
		if (sides % k)
			++result;
	}

	std::cout << result << std::endl;

	return 0;
}
