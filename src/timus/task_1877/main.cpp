#include <iostream>
#include <string>


int main()
{
	int pass1, pass2;
	std::cin >> pass1 >> pass2;

	bool unlock1 = (pass1 % 2 == 0);
	bool unlock2 = (pass2 % 2 == 1);

	std::string answer = (unlock1 || unlock2) ? "yes" : "no";
	std::cout << answer << std::endl;
	return 0;
}
