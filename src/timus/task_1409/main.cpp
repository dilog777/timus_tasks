#include <iostream>


int main()
{
	int hit1, hit2;
	std::cin >> hit1 >> hit2;

	int total = hit1 + hit2 - 1;

	int mis1 = total - hit1;
	int mis2 = total - hit2;
	std::cout << mis1 << " " << mis2 << std::endl;
	return 0;
}
