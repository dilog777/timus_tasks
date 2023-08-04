/*
Вы не поверите, но однажды в древности произошла такая история. На заседании 
круглого стола король Артур встал и сказал: «Пусть каждый рыцарь, сидящий от 
меня справа не более чем на b мест и не менее чем на a мест, получит по c 
золотых монет из моего кармана». Если занумеровать всех рыцарей числами от 1 до 
N против часовой стрелки, так что, рыцарь, сидящий справа от Артура, получит 
номер 1, а рыцарь, сидящий слева от Артура, — номер N, то получается, что он 
раздал по c золотых монет рыцарям с номерами a, a + 1, …, b.

Затем благородные рыцари, посмотрев на щедрый поступок Артура, начали вставать 
по очереди против часовой стрелки и говорить свою тройку чисел ai, bi, ci 
(1 ≤ i ≤ N). После каждого такого высказывания рыцари, сидящие справа от короля 
Артура не более чем на bi мест и не менее чем на ai мест, получали по ci золотых 
монет от короля.

Поскольку каждый рыцарь был очень благороден, то либо ai > i, либо bi < i. Ваша 
задача — помочь рыцарям выяснить, сколько монет каждый из них получил в дар.

Исходные данные
В первой строке записано количество рыцарей короля Артура N (2 ≤ N ≤ 100000). В 
следующей строке записаны целые числа a, b и c, названные Артуром (
1 ≤ a ≤ b ≤ N; 1 ≤ c ≤ 10000). В следующих N строках перечислены тройки целых 
чисел ai, bi, ci, названные рыцарями (1 ≤ ai ≤ bi ≤ N; 1 ≤ ci ≤ 10000).

Результат
Выведите N чисел через пробел. i-е число должно равняться количеству монет, 
которое получил в дар i-й рыцарь.

Примеры
исходные данные		результат
4					2 4 4 2
2 3 2
2 4 1
3 4 1
1 2 1
1 1 1
--------------------------
7					5 19 23 19 11 8 5
1 7 1
2 3 4
3 5 3
1 2 1
5 7 4
2 4 10
3 4 2
1 6 3
*/

#include <vector>
#include <iostream>


int main()
{
	int n;
	std::cin >> n;

	std::vector<int> money(n + 1);

	int a, b, c;
	for (int i = 0; i <= n; ++i)
	{
		std::cin >> a >> b >> c;
		
		money[a - 1] += c;
		money[b] -= c;
	}

	int s = 0;
	for (int i = 0; i < n; ++i)
	{
		s += money[i];
		std::cout << s << " ";
	}

	return 0;
}
