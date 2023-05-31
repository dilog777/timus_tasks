#include <iostream>


int main()
{
	int a1, a2, a3;
	int b1, b2, b3;
	std::cin >> a1 >> b1;
	std::cin >> a2 >> b2;
	std::cin >> a3 >> b3;

	int a = a1 - a3;
	int b = b1 - b2;

	std::cout << a << " " << b << std::endl;
	return 0;
}
